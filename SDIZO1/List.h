#pragma once

class Element					//Klasa elementów listy
{
public:
	Element *previous;
	Element *next;
	int value;
	~Element()
	{
		previous = nullptr;
		next = nullptr;
	}
	Element()
	{
		previous = nullptr;
		next = nullptr;
	}

};


class List
{

private:
	
	
	int size;
	
	Element *head;		//Pocz¹tek listy	
	Element *tail;		//Koniec listy

public:
	void addFirstElement(int value);
	void addElement(int value, int index);
	void removeElement(int index);
	void printList();
	void addBeg(int value);
	void addEnd(int value);
	void removeBeg();
	void removeEnd();
	Element getTail();
	Element getHead();
	Element* find(int index); //Szuka elementu o danym numerze
	void load(std::string fileName);
	

	List();
	~List();
};

