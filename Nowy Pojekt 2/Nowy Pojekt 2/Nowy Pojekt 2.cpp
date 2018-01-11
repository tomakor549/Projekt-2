// Nowy Pojekt 2.cpp : Defines the entry point for the console application.
//
/*Księgarnia — Baza danych dla księgarni. W programie powinna istnieć możliwość dodania
nowej książki (tytuł, rok wydania, autor, cena), sprawdzenia dostępności książki, ceny itd. Liczba
dostępnych egzemplarzy powinna odzwierciedlać aktualny stan księgarni (np. po sprzedaży). Baza
powinna być serializowana do pliku*/

// skomentowane - (zmienić) trzeba przejrzeć!!!

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

struct data
{
	std::string author;
	std::string title;
	unsigned int publication_date;
	float price;

	struct data *next;
	struct data *previous;
	struct data *down;
};

struct data add_book(struct data *head, struct data *tail)		//dodawanie książki
{
	//head, tail z juz istniejacej listy, lub nowe = nullptr
	struct data *element;
	element = new struct data;
	element->author = "Ja";
	element->title = "Ja";
	element->publication_date = 2000;
	element->price = 20.90;

	struct data *help; //pomoc do listy
	help = head;

	while (help->next!=nullptr)
	{
		if (help->author.compare(element->author)==0) //jeśli autor z 'głowy' jest równy autorowi z elementu
		{
			struct data *suspend; //pomoc do listy
			suspend = help;

			while (suspend->down != nullptr)		//dopisz do końca listy (zmienić)
				suspend = help->down;

			suspend->down = element;
			element->next = nullptr;
			element->previous = nullptr;
			element->down = nullptr;
			delete suspend;
			break;
		}
		//jeśli nie:
		if (element->author.compare(help->author) < 0) //jeśli autor z pomocy jest dalej od autora z elementu (alfabetycznie od A-Z)
		{
			element->next = help->previous->next;
			help->previous->next = element;
			element->previous = help->previous;
			help->previous = element;
		}
		help = help->next;
	}
	
	delete help;
}

int main()
{
	struct data *head=nullptr;	//(zmienić)
	struct data *tail=nullptr;	//(zmienić)
	

	std::fstream plik;
	plik.open("books.bin", std::ios::in | std::ios::out |std::ios::binary);
		if (plik.good()==false)
		{
			std::cout << "Nie znaleziono bazy. Tworze nową" << std::endl;
		}
		else
		{
			
		}


    return 0;
}

