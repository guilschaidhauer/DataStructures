#include <iostream>
//#include "LinkedList.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree myBST;

	myBST.add(50);
	myBST.add(30);
	myBST.add(70);
	myBST.add(20);
	myBST.add(40);
	myBST.add(32);
	myBST.add(34);
	myBST.add(36);
	myBST.add(60);
	myBST.add(65);
	myBST.add(80);
	myBST.add(75);
	myBST.add(85);

	myBST.print();

	myBST.remove(70);
	myBST.print();

	system("pause");
	return 0;
}