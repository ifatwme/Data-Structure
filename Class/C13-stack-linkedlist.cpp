#include <iostream>
#include <math.h>
using namespace std;

struct stack
{
    int data;
    struct stack *left, *right;
};

class Stack
{
public:
    struct stack *start, *top, *temp;

    Stack();
    void push(int val);
    void pop();
    void freeStack();
};

Stack::Stack()
{
    start = new struct stack;
    start -> right = NULL;
    start -> left = NULL;
    top = start;
}

void Stack::push(int value)
{
    temp = new struct stack;
    temp -> data = value;

    temp -> left = top;
    temp -> right = NULL;
    
    top -> right = temp;
    top = temp;
}

void Stack::pop()
{
    int value;
    if (top == start)
    {
        cout << "the stack is empty!" << endl;
        return;
    }
    else
    {
        temp = top -> left;
        temp -> right = NULL;
        top -> left = NULL;

        value = top -> data;
        cout << value << endl;
        free(top);
        top = temp;
    }
}

// if start == top then it's empty
void Stack::freeStack()
{
    while(start != top)
    {
        temp = start;
        start = start -> right;
        free(temp);
    }
}

int main()
{
    int length, i;
    cout << "enter a length for stack: " << endl;
    cin >> length;

    Stack mystack = Stack();

    for (i = 0; i < length; i++)
    {
        mystack.push(i);
    }

    for(i = 0; i < length; i++)
    {
        mystack.pop();
    }

    mystack.freeStack();
    mystack.pop();

    return 0;
}