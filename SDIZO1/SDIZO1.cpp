// SDIZO1.cpp : Defines the entry point for the console application.

/*
Program testuj¹cy struktuy Danych
Autor: Kacper Koryluk


*/
//

#include "stdafx.h"

using namespace std;

char decision;
int value, index;	//Wartoœæ i indeks elementu, u¿ywane w menu jako zmienne tymczasowe.

Array *testArray = new Array();					//Kontenery
BinaryHeap *testBinaryHeap = new BinaryHeap();
List *testList = new List();



void arrayMenu()	//Menu tablicy
{
	cout << "Menu tablicy: " << endl
		<< "Funkcje:" << endl
		<< "1 - Wyswietla tablice." << endl
		<< "2 - Dodaje element o podanej wartosci w wybrane miejsce." << endl
		<< "3 - Usuwa element z wybranego miejsca." << endl
		<< "4 - Wyszukuje element o podanym indeksie." << endl;
	do
	{
		decision = _getch();
		switch (decision)
		{
		case '1':
			testArray->print();
			if (testArray->getSize() == 0)
			{
				cout << "Brak elementow" << endl;
			}
			break;
		case '2':
			do {
				cout << "Podaj indeks elementu, indeks wiekszy ni¿ rozmiar kontenera spowoduje wstawienie elementu na koniec: " << endl;
				cin >> index;
				while (cin.fail())
				{
					cout << "Blad, podaj liczbe calkowita!" << endl;
					cin.clear();
					cin.ignore();
					cin >> index;
				}
				if (index < 0)
				{
					cout << "Nieprawidlowy indeks, podaj ponownie!" << endl;
				}
			} while (index < 0);
			cout << "Podaj wartosc elementu: " << endl;
			cin >> value;
			while (cin.fail())
			{
				cout << "Blad, podaj liczbe calkowita!" << endl;
				cin.clear();
				cin.ignore();
				cin >> value;
			}
			
			if (index == 0)
			{
				testArray->addFirst(value);
			}
			else if (index >= testArray->getSize())
			{
				testArray->addLast(value);
			}
			else
			{
				testArray->addElement(value, index);
			}

			break;
		case '3':
			if (testArray->getSize() > 0)
			{

				do {
					cout << "Podaj indeks elementu, indeks wiekszy niz rozmiar kontenera spowoduje usuniecie elementu z konca " << endl;
					cin >> index;
					while (cin.fail())
					{
						cout << "Blad, podaj liczbe calkowita!" << endl;
						cin.clear();
						cin.ignore();
						cin >> index;
					}
					if (index < 0)
					{
						cout << "Nieprawidlowy indeks, podaj ponownie!" << endl;
					}
				} while (index < 0);
				if (index == 0)
				{
					testArray->removeFirst();
				}
				else if (index >= testArray->getSize() - 1)
				{
					testArray->removeLast();
				}
				else
				{
					testArray->removeElement(index);
				}
			}
			else
			{
				cout << "Tablica pusta, brak elementow do usuniecia." << endl;
			}

			break;
		case '4':
			do {
				cout << "Podaj indeks elementu: " << endl;
				cin >> index;
				while (cin.fail())
				{
					cout << "Blad, podaj liczbe calkowita!" << endl;
					cin.clear();
					cin.ignore();
					cin >> index;
				}
				if (index < 0 || index > testArray->getSize() - 1)
				{
					cout << "Nieprawidlowy indeks, podaj ponownie!" << endl;
				}
			} while (index < 0 || index > testArray->getSize() - 1);
			cout << "Element o podanym indeksie: " << testArray->findElement(index) << endl;
			break;
		}
	} while (decision != 27);
	cout << "Powrocono do menu glownego" << endl;
	decision = 0; //Zerujê decyzjê, ¿eby zapobiec ca³kowitemu wyjœciu z programu
}
void heapMenu()		//Menu kopca
{

	cout << "Menu kopca: " << endl
		<< "Funkcje:" << endl
		<< "1 - Wyswietla kopiec." << endl
		<< "2 - Dodaje element o podanej wartosci do kopca" << endl
		<< "3 - Usuwa korzen." << endl
		<< "4 - Wyszukuje element o podanym indeksie." << endl;

	do
	{
		decision = _getch();
		switch (decision)
		{
		case '1':
			testBinaryHeap->print();
			if (testBinaryHeap->getSize() == 0)
			{
				cout << "Brak elementow" << endl;
			}
			break;
		case '2':
			cout << "Podaj wartosc elementu: " << endl;
			cin >> value;
			while (cin.fail())
			{
				cout << "Blad, podaj liczbe calkowita!" << endl;
				cin.clear();
				cin.ignore();
				cin >> value;
			}
			testBinaryHeap->push(value);
			break;
		case '3':
			if (testBinaryHeap->getSize() > 0)
			{
				testBinaryHeap->pop();
				cout << "Usunieto korzen." << endl;
			}
			else
			{
				cout << "Brak elementow do usuniecia!" << endl;
			}
			break;
		case '4':
			do {
				cout << "Podaj indeks elementu: " << endl;
				cin >> index;
				while (cin.fail())
				{
					cout << "Blad, podaj liczbe calkowita!" << endl;
					cin.clear();
					cin.ignore();
					cin >> index;
				}
				if (index < 0 || index > testBinaryHeap->getSize() - 1)
				{
					cout << "Nieprawidlowy indeks, podaj ponownie!" << endl;
				}
			} while (index < 0 || index > testBinaryHeap->getSize()-1);
			cout << "Element o podanym indeksie: " << testBinaryHeap->findElement(index) << endl;
			break;
		}
	} while (decision != 27);
	cout << "Powrocono do menu glownego" << endl;
	decision = 0;
}
void listMenu()		//Menu listy
{

	cout << "Menu listy: " << endl
		<< "Funkcje:" << endl
		<< "1 - Wyswietla liste." << endl
		<< "2 - Dodaje element o podanej wartosci w wybrane miejsce." << endl
		<< "3 - Usuwa element z wybranego miejsca." << endl
		<< "4 - Wyszukuje element o podanym indeksie." << endl;
	
	do
	{
		decision = _getch();
		switch (decision)
		{
		case '1':
			testList->printList();
			if (testList->getSize() == 0)
			{
				cout << "Brak elementow." << endl;
			}
			break;
		case '2':
			cout << "Podaj indeks elementu, indeks wiekszy od rozmiaru tablicy spowoduje dodanie elementu na koncu" << endl;
			do {
				cin >> index;
				while (cin.fail())
				{
					cout << "Blad, podaj liczbe calkowita!" << endl;
					cin.clear();
					cin.ignore();
					cin >> index;
				}
				if (index < 0)
				{
					cout << "Indeks musi byc dodatni!" << endl;
				}
			} while (index < 0);
			cout << "Podaj wartosc elementu" << endl;
			cin >> value;
			while (cin.fail())
			{
				cout << "Blad, podaj liczbe calkowita!" << endl;
				cin.clear();
				cin.ignore();
				cin >> value;
			}
			testList->addElement(value, index);
			break;
		case '3':
			if (testList->getSize() > 0)
			{
				cout << "Podaj indeks elementu" << endl;
				do {
					cin >> index;
					while (cin.fail())
					{
						cout << "Blad, podaj liczbe calkowita!" << endl;
						cin.clear();
						cin.ignore();
						cin >> index;
					}
					if (index < 0)
					{
						cout << "Indeks musi byc dodatni!" << endl;
					}
				} while (index < 0);
				testList->removeElement(index);
			}
			else
			{
				cout << "Usuwanie elementu nie powiodlo sie! Tablica jest pusta" << endl;
			}
			break;
		case '4':
			do {
				cout << "Podaj indeks elementu: " << endl;
				cin >> index;
				while (cin.fail())
				{
					cout << "Blad, podaj liczbe calkowita!" << endl;
					cin.clear();
					cin.ignore();
					cin >> index;
				}
				if (index < 0 || index > testList->getSize() - 1)
				{
					cout << "Nieprawidlowy indeks, podaj ponownie!" << endl;
				}
			} while (index < 0 || index > testList->getSize() - 1);
			cout << "Element o podanym indeksie: " << testList->find(index)->value << endl;
			break;
		}
	} while (decision != 27);
	cout << "Powrocono do menu glownego" << endl;
	decision = 0;
}

void menu()	//Menu do prezentacji programu
{
	cout << "Program testujacy struktury danych. Struktura tworzona jest na podstawie dostarczonego pliku \"test\"." << endl
		<< "Funkcje:" << endl
		<< "l - Tworzy liste i przechodzi do menu listy." << endl
		<< "k - Tworzy kopiec i przechodzi do menu kopca." << endl
		<< "t - Tworzy tablice i przechodzi do menu tablicy" << endl
		<< "c - Czysci ekran." << endl;
	do
	{
		decision = _getch();
		switch (decision)
		{
		case 'l':
			testList->load("test.txt");
			listMenu();
			break;
		case 'k':
			testBinaryHeap->load("test.txt");
			heapMenu();
			break;
		case 't':
			testArray->loadFromFile("test.txt");
			arrayMenu();
			break;
		case 'c':
			system("cls");
			cout << "Program testujacy struktury danych. Struktura tworzona jest na podstawie dostarczonego pliku \"test\"." << endl
				<< "Funkcje:" << endl
				<< "l - Tworzy liste i przechodzi do menu listy." << endl
				<< "k - Tworzy kopiec i przechodzi do menu kopca." << endl
				<< "t - Tworzy tablice i przechodzi do menu tablicy" << endl
				<< "c - Czysci ekran." << endl;
			break;
		}
	} while (decision != 27);
}


void testMenu() //Menu do gromadzenia wyników pomiaru czasu
{

}

int main()
{




/*
Zrobiæ menu do testów.

*/


menu();





delete testArray;
delete testBinaryHeap;
delete testList;
	system("pause");
    return 0;
}

