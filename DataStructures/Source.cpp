#include <iostream>
#include "LinkedList.h"
//#include "BinarySearchTree.h"
#include "Hashtable.h"

using namespace std;

int main()
{
	Hashtable myHashTable;
	
	Item item1;
	item1.name = "Guilherme";
	item1.phoneNumber = "1234";

	Item item2;
	item2.name = "Guilherme";
	item2.phoneNumber = "5678";

	myHashTable.add(item1);
	myHashTable.add(item2);

	cout << myHashTable.toString() << endl;

	system("pause");
	return 0;
}