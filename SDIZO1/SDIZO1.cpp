// SDIZO1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

char decision;


void arrayMenu()	//Pobiera dane z pliku, tworzy tablicê i przechodzi do menu tablicy
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
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		}
	} while (decision != 27);
	cout << "Powrocono do menu glownego" << endl;
	decision = 0; //Zerujê decyzjê, ¿eby zapobiec ca³kowitemu wyjœciu z programu
}
void heapMenu()		//Pobiera dane z pliku, tworzy kopiec i przechodzi do menu kopca
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
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		}
	} while (decision != 27);
	cout << "Powrocono do menu glownego" << endl;
	decision = 0;
}
void listMenu()		//Pobiera dane z pliku, tworzy listê i przechodzi do menu listy
{

	cout << "Menu listy: " << endl
		<< "Funkcje:" << endl
		<< "1 - Wyswietla liste." << endl
		<< "2 - Dodaje element o podanej wartosci w wybrane miejsce." << endl
		<< "3 - Usuwa element z wybranego miejsca." << endl
		<< "4 - Wyszukuje element o podanym indeksie." << endl;
	decision = _getch();
	do
	{
		switch (decision)
		{
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
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
			listMenu();
			break;
		case 'k':
			heapMenu();
			break;
		case 't':
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
Array *testArray = new Array();
BinaryHeap *testBinaryHeap = new BinaryHeap();
List *testList = new List();



/*
W menu dodaæ zabezpieczenie przed dodaniem ujemnego indeksu, resztê sprawdziæ w metodach klas (za du¿y indeks, brak mo¿liwoœci usuniêcia elementu)

Wype³niæ menu listy, tablicy, kopca, zrobiæ menu do testów.

*/


menu();





delete testArray;
delete testBinaryHeap;
delete testList;
	system("pause");
    return 0;
}

