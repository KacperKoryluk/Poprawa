// SDIZO1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
Array *testArray = new Array();
BinaryHeap *testBinaryHeap = new BinaryHeap();
List *testList = new List();

//Blok testowy
testList->load("test.txt");
testList->printList();
testList->addElement(11115, 17);
testList->addElement(11114, 18);
testList->addElement(11113, 19);
testList->printList();
testList->removeElement(5);
testList->printList();

//Blok testowy

delete testArray;
delete testBinaryHeap;
delete testList;
	system("pause");
    return 0;
}

