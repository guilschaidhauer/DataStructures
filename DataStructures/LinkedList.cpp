#include "LinkedList.h"



LinkedList::LinkedList()
{
	count = 0;
}

LinkedList::~LinkedList()
{
	Node *focus;
	focus = firstNode;

	Node *previous;

	for (int i = 0; i < count; i++)
	{
		previous = focus;
		focus = focus->next;
		
		delete[] previous;
	}
}

string LinkedList::toString()
{
	string listString = "";

	Node *focus;
	focus = firstNode;

	for (int i = 0; i < count; i++)
	{
		listString += to_string(focus->data);

		if (i < count - 1)
			listString += ", ";

		focus = focus->next;
	}

	return listString;
}

void LinkedList::addNode(int data)
{
	if (firstNode == nullptr)
	{
		firstNode = new Node();
		firstNode->data = data;
	}
	else
	{
		Node *focus;
		focus = firstNode;

		for (int i = 0; i < count-1; i++)
		{
			focus = focus->next;
		}

		Node *newNode = new Node();
		newNode->data = data;
		newNode->previous = focus;
		focus->next = newNode;
	}

	count++;
}

void LinkedList::removeAt(int index)
{
	if (index < count && index >= 0)
	{
		Node *focus;
		focus = firstNode;

		for (int i = 0; i < index; i++)
		{
			focus = focus->next;
		}

		if (focus->previous != nullptr)
			focus->previous->next = focus->next;

		if (focus->next != nullptr)
			focus->next->previous = focus->previous;

		count--;
	}
}

int LinkedList::getAt(int index)
{
	if (index < count && index >= 0)
	{
		Node *focus;
		focus = firstNode;

		for (int i = 0; i < index; i++)
		{
			focus = focus->next;
		}

		return focus->data;
	}

	return NULL;
}
