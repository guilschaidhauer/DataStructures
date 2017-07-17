#include <iostream>
#include "LinkedList.h"
//#include "BinarySearchTree.h"

using namespace std;

int main()
{
	LinkedList<int> myList;

	myList.addNode(1);
	myList.addNode(2);
	myList.addNode(4);
	myList.addNode(8);
	myList.addNode(16);
	myList.addNode(32);
	myList.addNode(64);
	myList.addNode(128);

	cout << myList.toString() << endl;

	cout << myList.getAt(7) << endl;

	myList.removeAt(1);

	cout << myList.toString() << endl;

	system("pause");
	return 0;
}