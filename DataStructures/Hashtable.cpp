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

//Very simple hash function that returns the value of the first char in an int. Used only for testing purposes.
//See this like for better hash functions.
//http://www.cse.yorku.ca/~oz/hash.html
int Hashtable::hash(char * str)
{
	int index = str[0] - '0';

	return index;
}

void Hashtable::add(Item item)
{

}
