#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define n 30

class Stack1
{
public:
    Stack1();
    int pop();
    void push(int input);
    bool isfull();
    bool isempty();

private:
    int a[n], top;
};

Stack1::Stack1()
{
    top = -1;
}

int Stack1::pop()
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

void Stack1::push(int input)
{
    if(isfull())
        cout << "The stack is full!" <<endl;
    else
    {
        top++;
        a[top] = input;
    }
}

bool Stack1::isfull()
{
    if(top == n-1)
        return true;
    else
        return false;
}

bool Stack1::isempty()
{
    if(top == -1)
        return true;
    else
        return false;
}

// special stack for storing strings and characters of expression.
class Stack2
{
public:
    Stack2();
    string pop();
    void push(string input);
    bool isfull();
    bool isempty();
    int getlen();

private:
    string a[n];
    int top;
};

Stack2::Stack2()
{
    top = -1;
}

string Stack2::pop()
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

void Stack2::push(string input)
{
    if(isfull())
        cout << "The stack is full!" <<endl;
    else
    {
        top++;
        a[top] = input;
    }
}

bool Stack2::isfull()
{
    if(top == n-1)
        return true;
    else
        return false;
}

bool Stack2::isempty()
{
    if(top == -1)
        return true;
    else
        return false;
}

int Stack2::getlen()
{
    return top++;
}

int PrefixToPostfix(string pre, string infix, char* post)
{
    int len;

    // Constructing the needed methods.
    string PreToIn(string pre);
    int InToPost(string infix, char* post);

    infix = PreToIn(pre);
    cout <<infix;

    post[len], len = InToPost(infix, post);

    return post[len], len;
}

string PreToIn(string pre)
{
    string p1, p2, temp;
    int i, lenp;
    Stack2 mystack = Stack2();

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


int InToPost(string in, char* post)
{
    Stack1 mystack = Stack1();
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
    string infix, prefix = "*+DB-CA";
    char postfix[n];
    
    postfix[length], length = PrefixToPostfix(prefix, infix, postfix);
    infix = PreToIn(prefix);

    // Printing
    cout << "The prefix is: "<< prefix<<endl;
    cout << "The infix is: "<<infix<<endl;
    cout << "The postfix is: ";
    for (int i = 0; i < length; i++)
    {
        cout << postfix[i];
    }
    cout<<endl;

    return 0;
}