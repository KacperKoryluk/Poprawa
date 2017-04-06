#pragma once
#include "stdafx.h"
#include <string>
class BinaryHeap
{
private:
	int size;
	int *heap;
	std::string cr, cl, cp; //Zmienne potrzebne do wypisania kopca
public:
	int getSize();
	void setSize(int size);
	void push(int value);
	void pop();
	int findElement(int index);
	void print();
	void printBT(std::string sp, std::string sn, int v);
	void load(std::string fileName);


	
	BinaryHeap();
	~BinaryHeap();
};

