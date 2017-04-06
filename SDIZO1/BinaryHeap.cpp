#include "stdafx.h"
#include "BinaryHeap.h"




BinaryHeap::BinaryHeap()
{
	heap = nullptr;
	size = 0;
}


BinaryHeap::~BinaryHeap()
{
	delete[]heap;
}

int BinaryHeap::getSize()
{
	return this->size;
}

void BinaryHeap::setSize(int size)
{
	this->size = size;
}

void BinaryHeap::push(int value)
{

	int i, j;



	int *tempTab = new int[size + 1];
	for (int c = 0; c < size; c++)
	{
		tempTab[c] = heap[c];
	}
	delete[] heap;

	i = size++;
	j = floor((i - 1) / 2);	//Wzór na "rodzica" elementu
	tempTab[i] = value;
	int s = size;

	while (i > 0 && tempTab[j] < value)
	{
		int temp = tempTab[i];
		tempTab[i] = tempTab[j];
		tempTab[j] = temp;
		i = j;
		j = (i - 1) / 2;
	}




	heap = new int[size];
	for (int c = 0; c < size; c++)
	{
		heap[c] = tempTab[c];
	}
	delete[] tempTab;
}

void BinaryHeap::pop()
{
	heap[0] =heap[size - 1];							//Przesuwam ostatni liœæ na pozycjê korzenia


	int i, j, v;

	if (size--)		//Wykona siê tylko wtedy gdy rozmiar kopca bêdzie wiêkszy od 0, tutaj te¿ nastêpuje dekrementacja rozmiaru
	{
		v = heap[size];		//Zmienna tymczasowa przechowuj¹ca ostatni element kopca

		i = 0;
		j = 1;		//Lewy syn

		while (j < size)
		{
			if (j + 1 < size && heap[j + 1] > heap[j])	//Sprawdza czy lewy syn jest wiêkszy od prawego syna
			{
				j++;
			}
			if (v >= heap[j])
			{
				break;
			}

			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;		//Wzór na uzyskanie prawego syna
		}

		heap[i] = v;		//Umieszczenie wartoœci w kopcu
	}





	int *tempTab = new int[size];		//Struktura powinna zajmowaæ jak najmniej miejsca
	for (int i = 0; i < size; i++)
	{
		tempTab[i] = heap[i];
	}

	delete[] heap;
	heap = new int[size];

	for (int i = 0; i < size; i++)
	{
		heap[i] = tempTab[i];
	}
	delete[] tempTab;

}

int BinaryHeap::findElement(int index)
{
	return heap[index];
}

void BinaryHeap::print()
{

	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	printBT(" ", " ", 0);

	
}

void BinaryHeap::printBT(std::string sp, std::string sn, int v)
{
	std::string s;

	if (v < size)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBT(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << heap[v] << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl, 2 * v + 1);
	}
}

void BinaryHeap::load(std::string fileName)
{
	int tempSize;
	int tempVar; //Zmienna tymczasowa, przechowuje elementy odczytane z pliku
	std::fstream file;
	file.open(fileName, std::ios::in);

	if (file.is_open())
	{
		file >> tempSize;
		for (int i = 0; i < tempSize; i++)
		{
			file >> tempVar;
			push(tempVar);
		}
	}
	else
	{
		std::cerr << "Plik nie zostal otwarty!" << std::endl;
	}
	file.close();
}
