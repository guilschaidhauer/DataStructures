#pragma once
#include "LinkedList.h"
#include <string>

using namespace std;

struct Item {
	char name;
	string phoneNumber;
};

class Hashtable
{
public:
	Hashtable();
	~Hashtable();

	int hash(char *str);

	void add(Item item);

private:
	
	LinkedList<Item>* table[26];
};

