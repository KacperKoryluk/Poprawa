#include "stdafx.h"
#include "List.h"






List::List()	
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}


List::~List()	//Destruktor rozbiera list� usuwaj�c element po elemencie z pocz�tku
{
	for (int i = 0; i < size; i++)
	{
		removeBeg();
	}
}

void List::addFirstElement(int value)	//Je�eli lista jest pusta elementy zostan� dodane w taki spos�b
{
	Element *el = new Element();		//Tworz� element
	el->value = value;

	head = el;
	tail = el;

	head->next = tail;					//Ustawiam wska�niki
	head->previous = nullptr;

	tail->previous = head;
	tail->next = nullptr;
	size++;
	
}

void List::addElement(int value, int index)
{
	
	if (head == nullptr)
	{
		addFirstElement(value);
	}
	else
	{
		if (index == 0)
		{
			addBeg(value);
			return;
		}
		else if (index >= size)		//Je�li indeks przekracza rozmiar tablicy element zostanie dodany na ko�cu
		{
			addEnd(value);
			return;
		}
		else
		{
			Element *el = new Element;
			el->value = value;
			
			Element *el2 = find(index - 1);	//Elementy pomi�dzy kt�re chcemy doda� kolejny
			Element *el3 = el2->next;		//

			el->previous = el2;				//Ustawiam wska�niki nowego elementu
			el->next = el3;					//

			el2->next = el;					//Przestawiam wska�niki starych element�w
			el3->previous = el;				//

			size++;



		}



	}

}

void List::removeElement(int index)
{
	if (size > 0 && index <size)
	{
		if (index == 0)
		{
			removeBeg();
			return;
		}
		else if (index == size - 1)
		{
			removeEnd();
			return;
		}
		else
		{
			Element *temporary = find(index);			//Element usuwany

			Element *previous = temporary->previous;	//Elementy przed i po elemencie usuwanym
			Element *next = temporary->next;			//

			previous->next = next;						//Przestawiam wska�niki element�w otaczaj�cych usuwany
			next->previous = previous;					//

			delete temporary;
			size--;
			return;

		}
		
	}
	else
	{
		std::cerr << "Operacja nie powiodla sie, tablica pusta, lub wartosc indeksu przekroczyla rozmiar tablicy!" << std::endl;
	}
}

void List::printList()
{
	Element *el = head;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Element " << i << ": " << el->value << std::endl;
		el = el->next;

	}

}

void List::addBeg(int value)
{
	if (head == nullptr)	//Je�li nie ma element�w w li�cie zostanie utworzony pierwszy
	{
		addFirstElement(value);
	}
	else
	{
		head->previous = new Element();
		head->previous->value = value;
		head->previous->previous = nullptr;
		head->previous->next = head;		//Ustawiam wska�nik na nast�pny element obiektu przed "g�ow�" na sam� g�ow�

		if (size == 1)
		{
			tail = head;
		}

		head = head->previous;
		size++;
	}
}

void List::addEnd(int value)
{
	if (head == nullptr)
	{
		addFirstElement(value);
	}
	else
	{
		tail->next = new Element();		//Tworz� nowy element po ogonie

		tail->next->value = value;		//Ustawiam warto�� i wska�niki
		tail->next->next = nullptr;		//
		tail->next->previous = tail;	//

		if (size == 1)
		{
			head = tail;
		}

		tail = tail->next;               //Ustawiam wska�nik na ogon na dodany element

		size++;
	}
}

void List::removeBeg()
{
	if (size > 0)
	{
		if (size == 1)
		{
			head = nullptr;
			tail = nullptr;
			size = 0;
		}
		else
		{
			head = head->next;
			delete head->previous;
			head->previous = nullptr;
			size--;
		}
	}
	else
	{
		std::cout << "Nie mozna usunac, brak elementow!" << std::endl;
	}

}

void List::removeEnd()
{
	if (size > 0)
	{
		if (size == 1)
		{
			head = nullptr;
			tail = nullptr;
			size = 0;
		}
		else
		{
			tail = tail->previous;
			delete tail->next;
			tail->next = nullptr;
			size--;
		}
	}
}

Element * List::find(int index)
{
	Element *temporary;
	temporary = head;
	for (int i = 0; i < index; i++)
	{
		temporary = temporary->next;
	}


	return temporary;
}

void List::load(std::string fileName)
{
	std::fstream file;
	int temp;
	int tempSize;

	file.open(fileName, std::ios::in);

	if (file.is_open())
	{
		file >> tempSize;

		for (int i = 0; i < tempSize; i++)
		{
			file >> temp;
			addEnd(temp);
		}
	}
	else
		std::cerr << "Nie udalo sie otworzyc pliku!" << std::endl;
}

int List::getSize()
{
	return this->size;
}



