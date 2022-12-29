#include <bits/stdc++.h>
using namespace std;
#define n 30

// special stack for storing strings and characters of expression.
class Stack
{
public:
    Stack();
    string pop();
    void push(string input);
    bool isfull();
    bool isempty();
    int getlen();

private:
    string a[n];
    int top;
};

Stack::Stack()
{
    top = -1;
}

string Stack::pop()
{
    string value;
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

void Stack::push(string input)
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

int Stack::getlen()
{
    return top++;
}

string PrefixToInfix(string pre)
{
    string p1, p2, temp;
    int i, lenp;
    Stack mystack = Stack();

    lenp = pre.length();
    for(i = lenp; i >= 0; i--)
    {
        switch(pre[i])
        {
            case '+':
                p1 = mystack.pop();
                p2 = mystack.pop();
                temp = "(" + p1 + "+" + p2 + ")";
                mystack.push(temp);
                break;

            case '-':
                p1 = mystack.pop();
                p2 = mystack.pop();
                temp = "(" + p1 + "-" + p2 + ")";
                mystack.push(temp);
                break;

            case '*':
                p1 = mystack.pop();
                p2 = mystack.pop();
                temp = "(" + p1 + "*" + p2 + ")";
                mystack.push(temp);
                break;

            case '/':
                p1 = mystack.pop();
                p2 = mystack.pop();
                temp = "(" + p1 + "/" + p2 + ")";
                mystack.push(temp);
                break;

            default:
                temp = pre[i];
                mystack.push(temp);
                break;
        }
    }

    return mystack.pop();
}


int main()
{
    int length;
    string infix, prefix = "*+DB-CA";

    infix = PrefixToInfix(prefix);

    // Printing
    cout << "The prefix is: "<< prefix<<endl;
    cout << "The infix is: "<<infix<<endl;

    return 0;
}