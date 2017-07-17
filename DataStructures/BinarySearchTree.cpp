#include "BinarySearchTree.h"



BinarySearchTree::BinarySearchTree()
{
}


BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::add(int data)
{
	if (root == nullptr)
	{
		root = new Node();
		root->data = data;
	}
	else
	{	
		insert(data, root);
	}
}

void BinarySearchTree::remove(int data)
{
	Node *node = search(data, root);

	if (node == nullptr)
		return;

	//Case 1
	if (isLeaf(node))
	{
		if (node->data > node->parent->data)
		{
			node->parent->right = nullptr;
		}
		else if (node->data < node->parent->data)
		{
			node->parent->left = nullptr;
		}

		delete[] node;
	}
	//Case 2
	else if (node->left != nullptr && node->right == nullptr)
	{
		node->left->parent = node->parent;
		node->parent->right = node->left;
		delete[] node;
	}
	//Case 3
	else if (node->left == nullptr && node->right != nullptr)
	{
		node->right->parent = node->parent;
		node->parent->left = node->right;
		delete[] node;
	}
	//Case 4
	else if (node->left != nullptr && node->right != nullptr)
	{
		Node *replacement = findSmallest(node->right);

		if (replacement != nullptr)
		{
			if (replacement->data > replacement->parent->data)
			{
				replacement->parent->right = nullptr;
			}
			else if (replacement->data < replacement->parent->data)
			{
				replacement->parent->left = nullptr;
			}

			replacement->left = node->left;
			replacement->right = node->right;
			replacement->parent = node->parent;

			if (node->data > node->parent->data)
			{
				node->parent->right = replacement;
			}
			else if (node->data < node->parent->data)
			{
				node->parent->left = replacement;
			}
		}
	}
	
}

void BinarySearchTree::print()
{
	inorder(root);
	cout << endl;
}

bool BinarySearchTree::isLeaf(Node * node)
{
	if (node->left == nullptr && node->right == nullptr)
		return true;

	return false;
}

void BinarySearchTree::insert(int data, Node * leaf)
{
	if (data > leaf->data)
	{
		if (leaf->right != nullptr)
		{
			insert(data, leaf->right);
		}
		else
		{
			Node *newLeaf = new Node();
			newLeaf->data = data;
			newLeaf->parent = leaf;
			leaf->right = newLeaf;
		}
	}
	else if (data < leaf->data)
	{
		if (leaf->left != nullptr)
		{
			insert(data, leaf->left);
		}
		else
		{
			Node *newLeaf = new Node();
			newLeaf->data = data;
			newLeaf->parent = leaf;
			leaf->left = newLeaf;
		}
	}
}

Node* BinarySearchTree::search(int data, Node * node)
{
	if (node != NULL)
	{
		if (data == node->data)
			return node;

		if (data < node->data)
			return search(data, node->left);
		else
			return search(data, node->right);
	}
	else 
		return nullptr;
}

Node * BinarySearchTree::findSmallest(Node * node)
{
	if (node->left == nullptr)
		return node;
	else
		return findSmallest(node->left);

	return nullptr;
}
