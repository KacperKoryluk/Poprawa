// SDIZO1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
Array *testArray = new Array();
BinaryHeap *testBinaryHeap = new BinaryHeap();
List *testList = new List();

/*
W menu dodaæ zabezpieczenie przed dodaniem ujemnego indeksu, resztê sprawdziæ w metodach klas (za du¿y indeks, brak mo¿liwoœci usuniêcia elementu)


*/

//Blok testowy
testList->load("test.txt");
testList->printList();
testList->addElement(11115, 17);
testList->addElement(11114, 18);
testList->addElement(11113, 45);
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

