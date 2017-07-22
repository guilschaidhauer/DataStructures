#pragma once
#include "LinkedList.h"
#include <string>

#define tableSize 26

using namespace std;

struct Item {
	string name;
	string phoneNumber;

	inline bool operator==(Item a) {
		if (a.name == name && a.phoneNumber == phoneNumber)
			return true;
		else
			return false;
	}
};

class Hashtable
{
public:
	Hashtable();
	~Hashtable();

	int hash(string str);
	void add(Item item);
	void remove(Item item);
	string toString();

private:
	
	LinkedList<Item>* table[tableSize];
};

