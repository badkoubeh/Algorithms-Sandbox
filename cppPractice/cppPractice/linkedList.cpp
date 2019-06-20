#include "Header.h"
#include <iostream>

using namespace std;

//class Node
//{
//public:
//	int data;
//	Node *next;
//};


LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}
void LinkedList::CreateNode(int value)
{
	Node *temp = new Node;
	temp->data = value;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
		cout << "head created" << endl;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}
bool LinkedList::LoopDetection(Node *head)
{
	Node* slow = head;
	Node* fast = head;

	int count = 0;
	bool is_loop = false;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		count++;
		if (fast == slow)
		{
			cout << "Meeting point: " << count<< endl;
			is_loop = true;
			break;
		}
	}

	if (!is_loop)
		return false;

	// Finding Loop start point
	// Move slow to head and keep fast at meeting point
	// then move them at a same pace so they will meet at Loop Start
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	cout << "Loop Start Node: " << fast->data << endl;

	return true;

}

void LinkedList::DisplayNodes()
{
	Node *temp = new Node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
}

