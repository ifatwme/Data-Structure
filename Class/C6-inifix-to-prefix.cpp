#include <bits/stdc++.h>
using namespace std;
#define n 30

// This stack is used for infix to prefix conversion.
class Stack
{
public:
    Stack();
    int pop();
    void push(int input);
    bool isfull();
    bool isempty();

private:
    int a[n], top;
};

Stack::Stack()
{
    top = -1;
}

int Stack::pop()
{
    int value;
    if(isempty())
    {
        cout << "The stack is empty!" <<endl;
        return 0;
    }
    else
    {
        value = a[top];
        top--;
        return value;
    }
}

void Stack::push(int input)
{
    if(isfull())
        cout << "The stack is full!" <<endl;
    else
    {
        top++;
        a[top] = input;
    }
}

bool Stack::isfull()
{
    if(top == n-1)
        return true;
    else
        return false;
}

bool Stack::isempty()
{
    if(top == -1)
        return true;
    else
        return false;
}

// Conversion of infix to prefix
int InfixToPrefix(string infix, char* pre) 
{
    Stack mystack = Stack();
    int i, lenin, len = 0, j;
    char ch;

    lenin = infix.length();

    // loop over characters of the expression.
    for(i = lenin - 1; i >= 0; i--)
    {
        switch(infix[i])
        {
            case '(':
                ch = mystack.pop();
                pre[j++] = ch;
                len++;
                break;

            case '+':
                mystack.push(infix[i]);
                break;

            case '-':
                mystack.push(infix[i]);
                break;

            case '*':
                mystack.push(infix[i]);
                break;

            case '/':
                mystack.push(infix[i]);
                break;

            case ')':
                break;

            default:
                pre[j++] = infix[i];
                len++;
        }
    }

    // Reverse all the elements.
    for(j = 0; j < len/2; j++)
    {
        ch = pre[j];
        pre[j] = pre[len - 1 - j];
        pre[len - 1 - j] = ch;
    }

    return pre[len], len;
}

int main()
{
    int length;
    char prefix[n];
    string infix = "((A+B)*(C-D))";

    prefix[length], length = InfixToPrefix(infix, prefix);

    // Printing
    cout << "The infix is: "<<infix<<endl;
    cout << "The prefix is: ";
    for (int i = 0; i < length; i++)
    {
        cout << prefix[i];
    }
    cout<<endl;

    return 0;
}