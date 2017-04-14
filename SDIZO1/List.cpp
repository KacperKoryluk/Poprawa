#include "stdafx.h"
#include "List.h"






List::List()	
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}


List::~List()	//Destruktor rozbiera listê usuwaj¹c element po elemencie z pocz¹tku
{
	for (int i = 0; i < size; i++)
	{
		removeBeg();
	}
}

void List::addFirstElement(int value)	//Je¿eli lista jest pusta elementy zostan¹ dodane w taki sposób
{
	Element *el = new Element();		//Tworzê element
	el->value = value;

	head = el;
	tail = el;

	head->next = tail;					//Ustawiam wskaŸniki
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
		else if (index >= size)		//Jeœli indeks przekracza rozmiar tablicy element zostanie dodany na koñcu
		{
			addEnd(value);
			return;
		}
		else
		{
			Element *el = new Element;
			el->value = value;
			
			Element *el2 = find(index - 1);	//Elementy pomiêdzy które chcemy dodaæ kolejny
			Element *el3 = el2->next;		//

			el->previous = el2;				//Ustawiam wskaŸniki nowego elementu
			el->next = el3;					//

			el2->next = el;					//Przestawiam wskaŸniki starych elementów
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

			previous->next = next;						//Przestawiam wskaŸniki elementów otaczaj¹cych usuwany
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
	if (head == nullptr)	//Jeœli nie ma elementów w liœcie zostanie utworzony pierwszy
	{
		addFirstElement(value);
	}
	else
	{
		head->previous = new Element();
		head->previous->value = value;
		head->previous->previous = nullptr;
		head->previous->next = head;		//Ustawiam wskaŸnik na nastêpny element obiektu przed "g³ow¹" na sam¹ g³owê

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
		tail->next = new Element();		//Tworzê nowy element po ogonie

		tail->next->value = value;		//Ustawiam wartoœæ i wskaŸniki
		tail->next->next = nullptr;		//
		tail->next->previous = tail;	//

		if (size == 1)
		{
			head = tail;
		}

		tail = tail->next;               //Ustawiam wskaŸnik na ogon na dodany element

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



