#include <bits/stdc++.h>
using namespace std;
#define n 30

// This stack is used for postfix to infix conversion.
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

string PostfixToInfix(string post) 
{
    int i, lenp;
    string p1, p2, temp;
    Stack mystack = Stack();

    lenp = post.length();
    for (i = 0; i < lenp; i++)
    {
        switch(post[i])
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
                temp = post[i];
                mystack.push(temp);
                break;
        }
    }

    temp = mystack.pop();
    return temp;
}

int main()
{
    string infix, postfix = "AC-BD+*";

    infix = PostfixToInfix(postfix);
    
    // Printing
    cout << "The postfix is: "<< postfix<<endl;
    cout << "The infix is: "<<infix<<endl;

    return 0;
}