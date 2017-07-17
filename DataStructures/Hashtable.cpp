#include "Hashtable.h"



Hashtable::Hashtable()
{
	for (int i = 0; i < 20; i++)
	{
		table[i] = new LinkedList<Item>();
	}
}


Hashtable::~Hashtable()
{
}
