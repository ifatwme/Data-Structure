#include <iostream>

using namespace std;

#define n 200

class stack1
{
public:
    stack1();
    void push();
    int pop();
    bool isempty();
    bool isfull();
private:
    int st[n], top;
};

stack1::stack1()
{
    top = -1;
}

void stack1::push()
{
    if(isfull())
        cout << "Stack is full!";
    else
    {
        cout << "Please enter data for push: " <<endl;
        top++;
        cin >> st[top];
    }
}

int stack1::pop()
{
    int data;
    if(isempty())
    {
        cout << "Stack is empty!" <<endl;
        return 0;
    }
    else
    {
        data = st[top];
        top--;
        return data;
    }
}

bool stack1::isempty()
{
    if(top == -1)
        return true;
    else
        return false;
}

bool stack1::isfull()
{
    if(top == n-1)
        return true;
    else
        return false;
}

int main()
{
    stack1 mystack = stack1();

    bool mineisempty = mystack.isempty();
    if(mineisempty)
        cout << "The stack is empty!" <<endl;

    for(int i = 0; i<=4; i++)
        mystack.push();

    int temp;
    for(int i = 0; i <= 4; i++)
    {
        temp = mystack.pop();
        cout << temp<< "\t";
    }

    return 0;
}
