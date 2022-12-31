// c++ program for double linked list.

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *right, *left;
}*start, *last;

void InsertLast()
{
	Node *temp;
	int value;
	cout << "Enter to insert: " << endl;
	cin >> value;

	temp = new struct Node;
	temp -> data = value;
	
	if (start == NULL)
	{
		start = temp;
		start -> left = NULL;
		start -> right = NULL;
		last = start;
		return;
	}

	last -> right = temp;
	temp -> left = last;
	temp -> right = NULL;

	last = temp;
}

// iterate until specific position left to right
void InsertPos()
{
	Node *temp;
	int value, pos;
	cout << "Enter value: " << endl;
	cin >> value;
	cout << "Enter position: " << endl;
	cin >> pos;

	temp = new struct Node;
	temp -> data = value;

	if (start == NULL)
	{
		temp -> right = NULL;
		temp -> left = NULL;
		start = temp;
		last = start;
		return;
	}

	else if (pos == 1)
	{
		temp -> left = NULL;
		temp -> right = start;
		start = temp;
	}
	else
	{
		Node *temp2;
		temp2 = start;
		while(pos - 1 != 1)
		{
			temp2 = temp2 -> right;
			pos--;
		}
		temp -> left = temp2;
		temp -> right = temp2 -> right;
		temp2 -> right = temp;
	}
}

// iterate over each element
void PrintList()
{
	if (start == NULL)
	{
		cout << "This list is empty!" << endl;
		return;
	}

	// for (temp = start -> right; temp != NULL; temp = temp -> right)
	Node *temp = start;
	while (temp != NULL)
	{
		cout << temp -> data << " " ;
		temp = temp -> right;
	}
	cout << endl;
}

// iterate right to left
void DeleteList()
{
	Node *temp;
	while (last != NULL)
	{
		temp = last;
		last = last -> left;
		free(temp);
	}
	start = NULL;
}

// Driver's code
int main()
{
	start = NULL;

	InsertLast();

	InsertPos();
	
	PrintList();

	DeleteList();

	PrintList();

	return 0;
}

