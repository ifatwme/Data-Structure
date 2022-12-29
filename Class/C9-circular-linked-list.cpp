// A simple C++ program for
// circular linked list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	// Constructor of the first node.
	Node(int value)
	{
		data = value;
		next = NULL;
	}
};

class circularlinkedlist
{
private:
	Node *head;

public:
	circularlinkedlist()
	{
		head -> next = head;
	}

	void insert(int value)
	{
		Node* temp;
		Node* t;

		temp = new Node(value);
		if (head -> next == head)
		{
			head -> next = temp;
			temp -> next = head;
			return;
		}

		else
		{
			t = head;
			while (t ->next != head)
			{
				t = t -> next;
			}
			t -> next = temp;
			temp -> next = head;
		}
	}

	void Delete()
	{
		Node* temp;
		if(head -> next == head)
		{
			cout << "nothing to delete!" << endl;
			return;
		}
		temp = head;
		head = head -> next;
		free(temp);

	}

	void freelist()
    {
        Node* temp;
        while (temp -> next != head)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

	void print()
	{
		if (head -> next == head)
		{
			cout << "This circular list is empty!" << endl;
			return;
		}

		Node* temp = head;
		while(temp -> next != head)
		{
			cout << temp -> data << " -> ";
			temp = temp -> next;
		}
		cout << endl;
	}
};


int main()
{
	// get the value.
	int value;
	cout << "Enter first value of the list: " << endl;
	cin >> value;

	circularlinkedlist mylist;
	mylist.insert(value);
	mylist.print();
	mylist.freelist();

	return 0;
}