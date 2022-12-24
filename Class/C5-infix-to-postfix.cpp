#include <bits/stdc++.h>
using namespace std;
#define n 30

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

int InfixToPostfix(string in, char* post)
{
    Stack mystack = Stack();
    int len = 0, lenin, i, j=0;
    char ch;

    lenin = in.length();

    for(i = 0; i < lenin; i++)
    {
        switch(in[i])
        {
            case '(':
                break;

            case ')':
                ch = mystack.pop();
                post[j++] = ch;
                len++;
                break;

            case '+':
                mystack.push(in[i]);
                break;

            case '-':
                mystack.push(in[i]);
                break;

            case '/':
                mystack.push(in[i]);
                break;

            case '*':
                mystack.push(in[i]);
                break;

            default:
                ch = in[i];
                post[j++] = ch;
                len++;
        }
    }

    // End of the string or char list.
    post[j] = '\0';
    
    return post[len], len;
}

int main()
{
    int length;
    string infix = "((A+B)*(C-D))";
    char postfix[n];
    
    postfix[length], length = InfixToPostfix(infix, postfix);

    // Printing
    cout << "The infix is: "<<infix<<endl;
    cout << "The postfix is: ";
    for (int i = 0; i < length; i++)
    {
        cout << postfix[i];
    }
    cout<<endl;

    return 0;
}