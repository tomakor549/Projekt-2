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

struct data *add_book(struct data *head, struct data *tail)		//dodawanie książki
{
	//head, tail z juz istniejacej listy, lub nowe = nullptr
	struct data *element;
	element = new struct data;
	element->author = "Ja";
	element->title = "Ja";
	element->publication_date = 2000;
	element->price = 20.90;
	element->next = nullptr;
	element->previous = nullptr;
	element->down = nullptr;

	struct data *help; //pomoc do listy
	help = head->next;

	if (element->author.compare(head->author) < 0)
	{
		head->previous = element;
		element->next = head;
		head = element;
		return head;
	}
	else
	while (help!=nullptr)
	{
		if (help->author.compare(element->author)==0) //jeśli autor z 'głowy' jest taki sam jak autor z elementu
		{
			while (help->down != nullptr)
			{
				help = help->down;
			}
			help->down = element;
			break;
		}
		//jeśli nie:

		if (help->next == nullptr)		//nie wykonało powyższych kroków i się zgadza
		{
			help->next = element;
			element->previous = help;
			break;
		}

		if (element->author.compare(help->next->author) < 0) 
		{
			//Wykonuje jeśli autor z elementu powinien być przed autorem z pomocy (alfabetycznie od A-Z)
			element->next = help->previous->next;
			help->previous->next = element;
			element->previous = help->previous;
			help->previous = element;
			break;
		}


		help = help->next;
	}
	return head;
}

void write()
{

}

int main()
{
	struct data *head = nullptr;
	

	std::fstream plik;
	plik.open("books.bin", std::ios::in | std::ios::out |std::ios::binary);
		if (plik.good()==false)
		{
			std::cout << "Nie znaleziono bazy. Tworze nową" << std::endl;
		}
		else
		{
			
		}

		head=add_book();



    return 0;
}

