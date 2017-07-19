#pragma once
#include "LinkedList.h"
#include <string>

#define tableSize 26

using namespace std;

struct Item {
	string name;
	string phoneNumber;
};

class Hashtable
{
public:
	Hashtable();
	~Hashtable();

	int hash(string str);
	void add(Item item);
	string toString();

private:
	
	LinkedList<Item>* table[tableSize];
};

