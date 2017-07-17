#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* parent;

	Node()
	{
		data = NULL;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};


class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	void add(int data);
	void remove(int data);
	Node* search(int data, Node *node);
	Node* findSmallest(Node *node);

	void print();

private:
	Node *root;

	bool isLeaf(Node *node);
	void insert(int data, Node *leaf);
};

