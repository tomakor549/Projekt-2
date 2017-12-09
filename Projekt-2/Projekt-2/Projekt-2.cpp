// Projekt-2.cpp : Defines the entry point for the console application.
//
/*Księgarnia — Baza danych dla księgarni.
W programie powinna istnieć możliwość dodania nowej książki (tytuł, rok wydania, autor, cena),
sprawdzenia dostępności książki, ceny itd.
Liczba dostępnych egzemplarzy powinna odzwierciedlać aktualny stan księgarni (np. po sprzedaży).
Baza powinna być serializowana do pliku.*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void add_book();

int reachability(); //dostępność

int amount(); //licznik

int main()
{
	int choise;
	bool repeat = true;

	cout << "Co chcesz zrobić?" << endl;
	cout << "1 - Dodać książkę" << endl;
	cout << "2 - Sprawdzić dostępność książki" << endl;
	cout << "3 - Zmiejszyć ilość książek" << endl;
	cout << "4 - Sprawdzić aktualny stan księgarni" << endl;
	cout << "5 - Zakończyć pracę" << endl;

	//Otwieram plik.
	std::fstream plik;
	plik.open("data.txt", std::ios::in | std::ios::out);
	if (!plik.good())
	{
		cout << "brak dostępu do bazy" << endl;
		return 0;
	}

	while (repeat)
	{
		cout << "Wybierz opcję: " << endl;
		cin >> choise;

		switch (choise)
		{
		case 1:	//Dodawanie książek
			add_book();
			break;
		case 2:	//Sprawdzaie dostępności książki, jej ceny itd.
			if (reachability())
				cout << "Książka jest dostępna";
			else
				cout << "Brak książki";
			break;
		case 3:	//Zmiejszanie ilości książek (sprzedawanie)
			amount();
			break;
		case 4:	//Aktualny stan księgarni
			break;
		case 5:	//Zanończenie pracy
			repeat = false;
			break;
		default:
			cout << "Nie ma takiej opcji" << endl;
			break;
		}
	}
	plik.close();

	return 0;
}