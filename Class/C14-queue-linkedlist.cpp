#include <iostream>
#include <math.h>
using namespace std;

struct queue
{
    int data;
    struct queue *left, *right;
};

class Queue
{
public:
    struct queue *front, *temp, *rear;

    Queue();
    void insert(int val);
    void del();
    void freeQueue();
};

Queue::Queue()
{
    front = new struct queue;
    front -> right = NULL;
    front -> left = NULL;
    rear = front;
}

void Queue::insert(int value)
{
    temp = new struct queue;
    temp -> data = value;

    temp -> left = rear;
    temp -> right = NULL;

    rear -> right = temp;
    rear = temp;
}

void Queue::del()
{
    if (front == rear -> right)
    {
        cout << "the queue is empty!" << endl;
        return;
    }
    
    temp = front -> right;
    temp -> left = NULL;

    cout << front -> data << endl;

    front -> right = NULL;
    front -> left = NULL;
    free(front);
    front = temp;
}

void Queue::freeQueue()
{
    while (front != NULL)
    {
        temp = front;
        front = front -> right;
        free(temp);
    }
}

int main()
{
    int length, i;
    cout << "enter length of the queue: " << endl;
    cin >> length;

    Queue myqueue = Queue();

    for(i = 0; i < length; i++)
    {
        myqueue.insert(i);
    }

    for(i = 0; i < length; i++)
    {
        myqueue.del();
    }

    myqueue.freeQueue();
    myqueue.del();

    return 0;
}