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
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void add_book(std::fstream &plik);					//dodawanie ksiazek

int reachability();									//dostępność

int amount();										//licznik

int wpisz(string choise);										//wpisywanie danych

int main()
{
	bool repeat = true;
	
	//Otwieram plik.
	std::fstream plik;

	cout << "Co chcesz zrobic?" << endl;
	cout << "1 - Dodac ksiazke" << endl;
	cout << "2 - Sprawdzic dostępnosc ksiazki" << endl;
	cout << "3 - Zmiejszyc ilosc ksiazek" << endl;
	cout << "4 - Sprawdzic aktualny stan ksiegarni" << endl;
	cout << "5 - Zakonczyc prace" << endl;

	cout << "Wybierz opcje: " << endl;
	while (repeat)
	{
		string choise;
		getline(cin,choise);

		switch (wpisz(choise))
		{
		case 1:	//Dodawanie książek
			add_book(plik);
			cout << "Wybierz opcje: " << endl;
			break;

		case 2:	//Sprawdzaie dostępności książki, jej ceny itd.
			reachability();
			cout << "Wybierz opcje: " << endl;
			break;

		case 3:	//Zmiejszanie ilości książek (sprzedawanie)
			amount();
			cout << "Wybierz opcje: " << endl;
			break;

		case 4:	//Aktualny stan księgarni
			//--------
			cout << "Wybierz opcje: " << endl;
			break;

		case 5: //Zanończenie pracy
			repeat = false;
			break;

		case 6:
			cout << "Blad przy wpisywaniu danych" << endl;
			cout << "Wybierz inna opcje: " << endl;
			break;

		default:
			break;
		}
	}

	return 0;
}