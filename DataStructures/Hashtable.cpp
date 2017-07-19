#include "Hashtable.h"


Hashtable::Hashtable()
{
	for (int i = 0; i < tableSize; i++)
	{
		table[i] = new LinkedList<Item>();
	}
}


Hashtable::~Hashtable()
{
}

//Very simple hash function.
//See this link for better hash functions.
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
	return index % (tableSize - 1);
}

void Hashtable::add(Item item)
{
	int index = hash(item.name);

	if (index < 0 || index >= tableSize)
		return;

	table[index]->add(item);
}

void Hashtable::remove(Item item)
{
	int index = hash(item.name);

	if (index < 0 || index >= tableSize)
		return;
	
	int listIndex = table[index]->getItemIndex(item);

	if (listIndex != -1)
		table[index]->removeAt(listIndex);
}

string Hashtable::toString()
{
	string prettyPrint = "";

	for (int i = 0; i < tableSize; i++)
	{
		prettyPrint += std::to_string(i) + "-";
		for (int j = 0; j < table[i]->size(); j++)
		{
			prettyPrint += table[i]->getAt(j).name + " " + table[i]->getAt(j).phoneNumber;
				
			if (j != table[i]->size() - 1)
				prettyPrint += " ||| ";
		}

		prettyPrint += "\n";
	}

	return prettyPrint;
}
