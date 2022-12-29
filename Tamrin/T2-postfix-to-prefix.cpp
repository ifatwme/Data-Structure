#include <iostream>
#include <bits/stdc++.h>

#define n 30

using namespace std;

// This stack is used for postfix to infix conversion.
class Stack1
{
public:
    Stack1();
    string pop();
    void push(string input);
    bool isfull();
    bool isempty();
    int getlen();

private:
    string a[n];
    int top;
};

Stack1::Stack1()
{
    top = -1;
}

string Stack1::pop()
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

void Stack1::push(string input)
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

int Stack1::getlen()
{
    return top++;
}

// This stack is used for infix to prefix conversion.
class Stack2
{
public:
    Stack2();
    int pop();
    void push(int input);
    bool isfull();
    bool isempty();

private:
    int a[n], top;
};

Stack2::Stack2()
{
    top = -1;
}

int Stack2::pop()
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

void Stack2::push(int input)
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

int PostfixToPrefix(string post, string infix, char* pre)
{
    int len;
    
    // Decelration of used convertions.
    string PostToIn(string post);
    int InToPre(string in, char* pre);

    // Process of conversion.
    infix = PostToIn(post);

    pre[len], len = InToPre(infix, pre);

    return pre[len], len;
}

// Convertion of postfix to infix
string PostToIn(string post) 
{
    int i, lenp;
    string p1, p2, temp;
    Stack1 mystack = Stack1();

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

// Conversion of infix to prefix
int InToPre(string infix, char* pre) 
{
    Stack2 mystack = Stack2();
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

    // To recognize the end of the char list.
    // pre[j] = '\0';

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
    string infix, postfix = "AC-BD+*";

    prefix[length], length = PostfixToPrefix(postfix, infix, prefix);
    infix = PostToIn(postfix);
    
    // Printing
    cout << "The postfix is: "<< postfix<<endl;
    cout << "The infix is: "<<infix<<endl;
    cout << "The prefix is: ";
    for (int i = 0; i < length; i++)
    {
        cout << prefix[i];
    }
    cout<<endl;

    return 0;
}