#include <iostream>
#include "LinkedList.h"
//#include "BinarySearchTree.h"
#include "Hashtable.h"

using namespace std;

int main()
{
	Hashtable myHashTable;

	char myChar = '5';

	cout << myHashTable.hash(&myChar) << endl;

	system("pause");
	return 0;
}