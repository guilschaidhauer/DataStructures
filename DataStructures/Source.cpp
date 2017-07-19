#include <iostream>
#include "LinkedList.h"
//#include "BinarySearchTree.h"
#include "Hashtable.h"

using namespace std;

int main()
{
	Hashtable myHashTable;
	string myString = "55519999999";

	cout << myHashTable.hash(myString) << endl;

	system("pause");
	return 0;
}