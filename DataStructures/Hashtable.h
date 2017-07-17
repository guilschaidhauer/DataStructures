#pragma once
#include "LinkedList.h"
#include <string>

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

private:
	
	LinkedList<Item>* table[20];
};

