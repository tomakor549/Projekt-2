// Nowy Pojekt 2.cpp : Defines the entry point for the console application.
//
/*Księgarnia — Baza danych dla księgarni. W programie powinna istnieć możliwość dodania
nowej książki (tytuł, rok wydania, autor, cena), sprawdzenia dostępności książki, ceny itd. Liczba
dostępnych egzemplarzy powinna odzwierciedlać aktualny stan księgarni (np. po sprzedaży). Baza
powinna być serializowana do pliku*/

#include "stdafx.h"
#include <iostream>
#include "Functions.h"

int main(int argc, char** argv)
{
	auto wczytaj = argv[1];

	load(wczytaj);
    return 0;
}

