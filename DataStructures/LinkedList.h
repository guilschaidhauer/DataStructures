#pragma once
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* previous;

	Node()
	{
		data = NULL;
		next = nullptr;
		previous = nullptr;
	}
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	string toString();

	void addNode(int data);
	void removeAt(int index);
	int getAt(int index);

	int size() { return count; };

private:
	Node* firstNode;
	int count;
};

