#pragma once
#include <string>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* next;
	Node* previous;

	Node()
	{
		next = nullptr;
		previous = nullptr;
	}

	inline bool operator==(Node a) {
		if (a.data == data)
			return true;
		else
			return false;
	}
};

template <class T> class LinkedList
{
public:
	LinkedList<T>()
	{
		count = 0;
	}

	~LinkedList<T>()
	{
		Node<T> *focus = new Node<T>();
		focus = firstNode;

		Node<T> *previous = new Node<T>();

		for (int i = 0; i < count; i++)
		{
			previous = focus;
			focus = focus->next;

			delete[] previous;
		}
	};

	string toString()
	{
		string listString = "";

		Node<T> *focus = new Node<T>();
		focus = firstNode;

		for (int i = 0; i < count; i++)
		{
			listString += to_string(focus->data);

			if (i < count - 1)
				listString += ", ";

			focus = focus->next;
		}

		return listString;
	};
	
	void add(T data)
	{
		if (count == 0)
		{
			firstNode = new Node<T>();
			firstNode->data = data;
		}
		else
		{
			Node<T> *focus;
			focus = firstNode;

			for (int i = 0; i < count - 1; i++)
			{
				focus = focus->next;
			}

			Node<T> *newNode = new Node<T>();
			newNode->data = data;
			newNode->previous = focus;
			focus->next = newNode;
		}

		count++;
	};

	void removeAt(int index)
	{
		if (index < count && index >= 0)
		{
			Node<T> *focus;
			focus = firstNode;

			if (index == 0)
			{
				if (focus->next != nullptr)
				{
					focus->next->previous = nullptr;
					firstNode = focus->next;
				}
				else
				{
					firstNode = nullptr;
				}
			}
			else
			{
				for (int i = 0; i < index; i++)
				{
					focus = focus->next;
				}

				if (focus->previous != nullptr)
					focus->previous->next = focus->next;

				if (focus->next != nullptr)
					focus->next->previous = focus->previous;
			}

			count--;
		}
	};

	T getAt(int index)
	{
		if (index < count && index >= 0)
		{
			Node<T> *focus;
			focus = firstNode;

			for (int i = 0; i < index; i++)
			{
				focus = focus->next;
			}

			return focus->data;
		}
	};

	int getItemIndex(T item)
	{
		if (count <= 0)
			return -1;

		Node<T> *focus;
		focus = firstNode;

		for (int i = 0; i < count; i++)
		{
			if (item == focus->data)
				return i;

			focus = focus->next;
		}

		return -1;
	}

	int size() { return count; };

private:
	Node<T>* firstNode;
	int count;
};

