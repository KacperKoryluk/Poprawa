#include "stdafx.h"
#include "Array.h"



int Array::getSize()
{
	return this->size;
}

void Array::setSize(int size)
{
	this->size = size;
}

void Array::addElement(int value, int index)
{
	int *temporaryTab = new int[size + 1];

	for (int i = 0; i < index; i++)
	{
		temporaryTab[i] = tab[i];
	}

	temporaryTab[index] = value;

	for (int i = index + 1; i < size; i++)
	{
		temporaryTab[i] = tab[i];
	}

	size++;

	delete[]tab;
	tab = new int[size];

	for (int i = 0; i < size; i++)
	{
		tab[i] = temporaryTab[i];
	}
	delete[]temporaryTab;


}

void Array::removeElement(int index)
{
	int *temporaryTab = new int[size - 1];

	for (int i = 0; i < index; i++)
	{
		temporaryTab[i] = tab[i];
	}

	for (int i = index + 1; i < size; i++)
	{
		temporaryTab[i] = tab[i];
	}

	size--;

	delete[]tab;
	tab = new int[size];

	for (int i = 0; i < size; i++)
	{
		tab[i] = temporaryTab[i];
	}
	delete[]temporaryTab;


}

int Array::findElement(int index)
{
	return tab[index];
}

void Array::removeFirst()
{
	int *temporaryTab = new int[size - 1];

	for (int i = 1; i < size - 1; i++)	//Przepisujê od 1 elementu w górê, zerowy pomijam
	{
		temporaryTab[i] = tab[i];
	}

	size--;

	delete[]tab;
	tab = new int[size];

	for (int i = 0; i < size; i++)
	{
		tab[i] = temporaryTab[i];
	}
	delete[]temporaryTab;
}

void Array::removeLast()
{
	int *temporaryTab = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		temporaryTab[i] = tab[i];
	}

	size--;

	delete[]tab;
	tab = new int[size];

	for (int i = 0; i < size; i++)
	{
		tab[i] = temporaryTab[i];
	}
	delete[]temporaryTab;


}

void Array::addFirst(int value)
{
	int *temporaryTab = new int[size + 1];

	temporaryTab[size] = value;

	for (int i = 0; i < size; i++)
	{
		temporaryTab[i+1] = tab[i];
	}


	size++;

	delete[]tab;
	tab = new int[size];


	for (int i = 0; i < size; i++)
	{
		tab[i] = temporaryTab[i];
	}

	delete[]temporaryTab;

}

void Array::addLast(int value)
{
	int *temporaryTab = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		temporaryTab[i] = tab[i];
	}
	temporaryTab[size] = value;

	size++;

	delete[]tab;
	tab = new int[size];

	for (int i = 0; i < size; i++)
	{
		tab[i] = temporaryTab[i];
	}

	delete[]temporaryTab;
}

void Array::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Element " << i << ":" << tab[i] << std::endl;
	}
}

void Array::loadFromFile(std::string fileName)	//Przed wywo³aniem tej funkcji usun¹æ obiekt klasy Array
{

	std::fstream file;
	
	file.open(fileName, std::ios::in);	

	if (file.is_open())
	{
		file >> size;
		Array::Array(size);
		for (int i = 0; i < size; i++)
		{
			file >> tab[i];
		}
		
	}
	else
	{
		std::cerr << "Plik nie zostal otwarty!" << std::endl;
	}
	file.close();
}

Array::Array(int size)
{
	this->size = size;
	tab = new int[size];
}

Array::Array()
{
	size = 0;
	tab = nullptr;
}


Array::~Array()
{
	delete[]tab;
}
