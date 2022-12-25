#include <bits/stdc++.h>
using namespace std;
#define M 5
#define N 7
#define n 30

typedef struct
{
    int row;
    int col;
    int dir;
}element;

class Stack
{
    private:
        int top;
        element st[n];
    public:
        Stack();
        void push(element data);
        element pop();
        bool isempty();
        bool isfull();
        int gettop();
};
Stack::Stack()
{
    top = -1;
}

void Stack::push(element data)
{
    if (!isfull())
        top++;
        st[top] = data;
}

element Stack::pop()
{
    element data;
    if(!isempty())
    {
        data = st[top];
        top--;
        return data;
    }
    else
        return data;
}

bool Stack::isempty()
{
    if(top == -1)
        return true;
    else
        return false;
}

bool Stack::isfull()
{
    if(top == n-1)
        return true;
    else
        return false;
}

int Stack::gettop()
{
    return top;
}

void path(int maze[N][M], int enter[2], int exit[2], int mark[N][M])
{
    // 1: true, 0: false
    Stack stack = Stack();
    int i, top, row, col, dir, nrow, ncol, found = 0;

    // this matrix contains all the direction to move forward.
    int direction[8][2] = {{-1, 0},    // N
                           {-1, 1},    // NE
                           {0, 1},     // E
                           {1, 1},     // SE
                           {1, 0},     // S
                           {1, -1},    // SW
                           {0, -1},    // W
                           {-1, -1}};  // NW
    
    // instantiate first move.
    element position;
    mark[enter[0]][enter[1]] = 1;
    position.row = enter[0];
    position.col = enter[1];
    position.dir = 0;
    stack.push(position);

    top = stack.gettop();

    // make sure every position is seen.
    while (top > -1) 
    {
        position = stack.pop();
        row = position.row;
        col = position.col;
        dir = position.dir;

        // search in all 8 direction if the target is not found.
        while (dir < 8 && !found) 
        {
            nrow = row + direction[dir][0];
            ncol = col + direction[dir][1];

            // cheack if we have reached to our goal. 
            if(ncol == exit[1] && nrow == exit[0])
            {
                position.row = nrow;
                position.col = ncol;
                stack.push(position);
                found = 1;
            }

            else
            {
                // check whether the position is not a wall or seen befor.
                if (!maze[nrow][ncol] && !mark[nrow][ncol])
                {
                    mark[nrow][ncol] = 1;
                    position.row = row;
                    position.col = col;
                    position.dir = dir + 1;
                    stack.push(position);

                    row = nrow;
                    col = ncol;
                    dir = 0;
                }
                else
                    dir++;
            }
        }
        // update top to check whether the stack is empty.
        top = stack.gettop();

        if(found)
        {
            // reverse poped up positions in stack.(last in first out)
            Stack printstack = Stack();
            top = stack.gettop();
            while (top != -1)
            {
                position = stack.pop();
                printstack.push(position);
                top = stack.gettop();
            }

            // print path if it exists.
            cout << "the path is: " <<endl;
            cout << "row col" <<endl;
            top = printstack.gettop();
            while (top != -1)
            {
                position = printstack.pop();
                cout << position.row << "   " << position.col <<endl;
                top = printstack.gettop();
            }
        }
        else
        {
            cout << "the maze does not have path to target!" <<endl;
        }
    }
}

int main()
{
    // The position to exit. [0]->row, [1]->col
    int exit[2] = {4, 3};

    // the position to enter. [0]->row, [1]->col
    int enter[2] = {1, 1};

    // 0 indicates way and 1 indicates wall
    int maze[N][M] = {{1, 1, 1, 1, 1},
                      {1, 0, 0, 0, 1},
                      {1, 1, 1, 0, 1},
                      {1, 1, 0, 1, 1},
                      {1, 1, 1, 0, 1},
                      {1, 1, 1, 1, 1}};

    // mark matrix to mark the path if it is seen.
    int mark[N][M];

    path(maze, enter, exit, mark);

    return 0;
}