#pragma once

class Array
{
private:
	int size;
	int *tab;
public:
	int getSize();
	void setSize(int size);
	void addElement(int value, int index);
	void removeElement(int index);
	int findElement(int index); 
	void removeFirst();
	void removeLast();
	void addFirst(int value);
	void addLast(int value);
	void print();
	void loadFromFile(std::string fileName);

	Array(int size);
	Array();
	~Array();
};

