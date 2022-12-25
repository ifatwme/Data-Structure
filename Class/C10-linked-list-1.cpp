// Reference
// 1. Different methods to initialize a Linked List: https://www.geeksforgeeks.org/different-methods-to-initialize-a-linked-list/
// 2. C++ Assignment Operator Overloading: https://www.geeksforgeeks.org/cpp-assignment-operator-overloading/
// 3. Write a function to delete a Linked List: https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
// 4. Linked List Data Structure: https://favtutor.com/blog-details/linked-list-data-structure
// 5. How to free nodes in the linked list?: https://stackoverflow.com/questions/6417158/c-how-to-free-nodes-in-the-linked-list
// 6. Linked List - Delete the last node: https://www.alphacodingskills.com/ds/notes/linked-list-delete-the-last-node.php

#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        // constructor
        Node(int value)
        {
            data = value;
            next = NULL;
        }
};

class linkedlist 
{
private:
    // pointers to head and tail of list.
    Node *head, *tail;

public:
    // non-parameterized constructor
    linkedlist() 
    {
        head = NULL;
        tail = NULL;
    }

    // copy constructor to copy data of one list to another.
    // using operator assignment overloading.
    void operator=(const linkedlist& list)
    {
        if (list.head == NULL)
        {
            head = NULL;
            tail = NULL;
            return;
        }

        // initialize node pointer temp to head of list
        Node* temp = list.head;

        // create new linked list by copying the data of the list by iterate over loop.
        while (temp != NULL)
        {
            Node* nNode = new Node(temp ->data);
            if (head == NULL)
            {
                head = nNode;
                tail = nNode;
            }
            else
            {
                tail ->next = nNode;
                tail = nNode;
            }
            // iterate over each element of the list
            temp = temp ->next;
        }
    }
    
    // create a node for give value and then insert it at the end of linkedlist.
    void insert_end(int value)
    {
        // allocate temp node with given value.
        Node* temp;
        Node* t;

        temp = new Node(value);
        if (head == NULL)
        {
            head = temp;
            return;
        }
        else
        {
            t = head;
            while (t ->next != NULL)
            {
                t = t ->next;
            }
            t ->next = temp;
        }
    }

    // create another node to insert the value first of the linked list.
    void insert_first(int value)
    {
        Node* temp;

        temp = new Node(value);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp ->next = head;
            head = temp;
        }
    }

    // insert a node at the specific position.
    void insert_pos(int value, int position)
    {
        if (head == NULL)
        {return;}
        Node* nNode = new Node(value);

        // insert first
        if (position == 1)
        {
            nNode ->next = head;
            head = nNode;
        }
        // insert given position
        else
        {
            Node* temp = head;
            while (position - 1 != 1)
            {
                temp = temp ->next;
                position--;
            }
            nNode ->next = temp ->next;
            temp ->next = nNode;
        }
    }

    // Delete specific position of list
    void delete_pos(int position)
    {
        Node* temp;
        Node* t;
        int i, count = 0;

        if (head == NULL)
        {
            cout << "The list is empty!" << endl;
            return;
        }

        temp = head;
        if (position == 1)
        {
            head = temp ->next;
            free(temp);
        }
        else
        {
            // calculate length of the list
            while (temp != NULL)
            {
                temp = temp ->next;
                count++;
            }
            temp = head;
            if (position > 1 && position <= count)
            {
                // iterate until it reaches to given position
                while (position != 1)
                {
                    t = temp;
                    temp = temp ->next;
                    position--;
                }
                t ->next = temp ->next;
            }
            else
            {
                cout << "out of range!" << endl;
            }
            free(temp);
        }
    }

    // delete from begining of the list
    void delete_first()
    {
        Node* x;
        if(head == NULL)
        {
            return;
        }
        x = head;
        head = head ->next;
        free(x);
    }

    // delete from end of the list
    void delete_end()
    {
        Node* temp = head;
        if (head == NULL)
        {
            return;
        }
        Node* lNode;
        while (temp ->next ->next != NULL)
        {
            temp = temp ->next;
        }
        lNode = temp ->next;
        temp ->next = NULL;
        free(lNode);
    }

    // Delete entire list
    void freelist()
    {
        Node* temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    // print elements of linked list start from head
    void print()
    {
        if (head == NULL)
        {
            cout << "This list is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp ->data << " ";
            temp = temp ->next;
        }
        cout << endl;
    }
};

int main()
{
    int x, value, position;
    linkedlist list, nlist;
    
    while(1)
    {
        cout << "---------------------" << endl;
        // insertion
        cout <<"1. Insert first" << endl;
        cout <<"2. Insert position" << endl;
        cout <<"3. Insert end" << endl;
        // deletion
        cout <<"4. Delete first" << endl;
        cout <<"5. Delete position" << endl;
        cout <<"6. Delete last" << endl;

        cout <<"7. print list" << endl;
        cout <<"8. free list" << endl;
        cout <<"9. Create a copy and print both" << endl;
        cout <<"10. Exit" << endl;
        cout <<"Enter(1..10):" << endl;
        cout << "---------------------" << endl;
    
        cin >> x;

        switch(x)
        {
            case 1:
            { 
                cout << "Enter a number to insert to begin: " << endl;
                cin >> value;
                list.insert_first(value);
                break;
            }
            case 2:
            {
                cout << "Enter a number to insert to position: " << endl;
                cin >> value;
                cout << "Enter position: " << endl;
                cin >> position;
                list.insert_pos(value, position);
                break;
            }
            case 3:
            {
                cout << "Enter a number to insert at end: " << endl;
                cin >> value;
                list.insert_end(value);
                break;
            }
            case 4:
            {
                cout << "Delete first node: " << endl;
                list.delete_first();
                break;
            }
            case 5:
            {
                cout << "delete node in position: " << endl;
                cin >> position;
                list.delete_pos(position);
                break;
            }
            case 6:
            {
                cout << "delete last node: " << endl;
                list.delete_end();
                break;
            }
            case 7:
            {
                cout << "Linked list elements is: " << endl;
                list.print();
                break;
            }
            case 8:
            {
                list.freelist();
                list.print();
                break;
            }
            case 9:
            {
                cout << "Create a secondary list to test operator overloading \nand display it:" << endl;
                nlist = list;
                nlist.print();
                break;
            }
            case 10:
            {
                exit(1);
                break;
            }
        }
    }
    
    return 0;
}