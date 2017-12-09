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

void add_book();	//dodawanie ksiazek

int reachability();					//dostępność

int amount();						//licznik

int wpisz();						//wpisywanie danych

void check();

int main()
{
	int choise;
	bool repeat = true;
	
	//Otwieram plik.
	/*std::ifstream plik;
	plik.open("data.txt");
	if (!plik.good())
	{
		plik.close();
		cout << "Tworze nowa baze \"data.txt\"" << endl;
		std::ofstream plik;
		plik.open("data.txt", std::ios::in);
	}*/

	cout << "Co chcesz zrobic?" << endl;
	cout << "1 - Dodac ksiazke" << endl;
	cout << "2 - Sprawdzic dostępnosc ksiazki" << endl;
	cout << "3 - Zmiejszyc ilosc ksiazek" << endl;
	cout << "4 - Sprawdzic aktualny stan ksiegarni" << endl;
	cout << "5 - Zakonczyc prace" << endl;

	while (repeat)
	{
		cout << "Wybierz opcje: " << endl;
		choise = wpisz();

		switch (choise)
		{
		case 1:	//Dodawanie książek
			add_book();
			break;

		case 2:	//Sprawdzaie dostępności książki, jej ceny itd.
			reachability();
			break;

		case 3:	//Zmiejszanie ilości książek (sprzedawanie)
			amount();
			break;

		case 4:	//Aktualny stan księgarni
			break;

		case 5: //Zanończenie pracy
			repeat = false;
			break;

		default:
			cout << "Blad przy wpisywaniu danych" << endl;
			break;
		}
	}

	return 0;
}