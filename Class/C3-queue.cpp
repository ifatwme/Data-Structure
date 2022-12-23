#include <iostream>

using namespace std;

#define n 3

class queue1
{
public:
    queue1();
    void insert();
    int del();
    bool isempty();
    bool isfull();
private:
    int q[n], front, rear;
};
queue1::queue1()
{
    front = 0;
    rear = 0;
}

void queue1::insert()
{
    if(!isfull())
    {
        cout << "Please enter data for insert:" <<endl;
        cin >> q[rear];
        rear = (rear + 1) % n;
    }
    else
        cout << "Queue is full!" <<endl;
}

int queue1::del()
{
    int data;
    if(!isempty())
    {
        data = q[front];
        front = (front + 1) % n;
        return data;
    }
    else
    {
        cout << "Queue is empty!" << endl;
        return 0;
    }
}

bool queue1::isempty()
{
    if(front == rear)
        return true;
    else
        return false;
}

bool queue1::isfull()
{
    if((rear+1)%n == front)
        return true;
    else
        return false;
}

int main()
{
    queue1 myqueue = queue1();
    for(int i = 0; i <=n; i++)
    {
       myqueue.insert();
    }

    int data = myqueue.del();
    cout << data;
    return 0;
}
