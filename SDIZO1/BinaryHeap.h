#pragma once
class BinaryHeap
{
private:
	int size;
	int *heap;
public:
	int getSize();
	void setSize(int size);
	void push(int value);
	void pop(int index);
	int findElement(int index);
	void print();


	BinaryHeap(int size);
	BinaryHeap();
	~BinaryHeap();
};

