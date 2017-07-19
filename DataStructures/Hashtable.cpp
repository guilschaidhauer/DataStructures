#include "Hashtable.h"



Hashtable::Hashtable()
{
	for (int i = 0; i < 26; i++)
	{
		table[i] = new LinkedList<Item>();
	}
}


Hashtable::~Hashtable()
{
}

//Very simple hash function.
//See this like for better hash functions.
//http://www.cse.yorku.ca/~oz/hash.html
int Hashtable::hash(string str)
{
	int index = 0;
	
	char * charStr = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), charStr);
	charStr[str.size()] = '\0';

	for (int i = 0; i < str.size(); i++)
	{
		index += (int)charStr[i];
	}

	delete[] charStr;
	return index % 26;
}

void Hashtable::add(Item item)
{

}
