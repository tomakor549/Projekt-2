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
	double price;

	struct data *next;
	struct data *previous;
	struct data *down;
};

struct data *add_book(struct data *head, std::string author, std::string title, unsigned int publication_date, double price)		//dodawanie książki
{
	//head, tail z juz istniejacej listy, lub nowe = nullptr
	struct data *element;
	element = new struct data;
	element->author = author;
	element->title = title;
	element->publication_date = publication_date;
	element->price = price;
	element->next = nullptr;
	element->previous = nullptr;
	element->down = nullptr;
	if (head == nullptr)			//(zmiana) - jak dodam wczytywanie z pliku to musze to przemyśleć
	{
		head = element;
		return element;
	}
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
	{
		if (head->next == nullptr)
		{
			head->next = element;
			element->previous = head;
			return head;
		}
	}
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

unsigned int verification(std::string choice)
{
	int characters = choice.length();

	if (characters == 1)
	{
		characters = atoi(choice.c_str());
		return characters;
	}
	else
		return 6;

	return 0;
}

void write(struct data *head)
{
	//struct data *help;
	while (head != nullptr)
	{
		std::cout << head->author << " |||||||| ";
		head = head->next;
	}
}

struct data *user_switch(struct data *head, int choice)
{
	if (choice == 1)
	{
		std::string author;
		std::string title;
		unsigned int publication_date;
		double price;
		std::cout << "Wypisz autora:" << std::endl;
		getline(std::cin, author);					//(zmiana) - dodać sprawdzanie + ewentualną zmiana perwszej litery na dużą
		std::cout << "Wypisz tytul:" << std::endl;
		getline(std::cin, title);					//(zmiana) - dodać sprawdzanie + ewentualną zmiana perwszej litery na dużą
		std::cout << "Wypisz date wydania:" << std::endl;
		std::cin>> publication_date;
		std::cout << "Wypisz cene:" << std::endl;
		std::cin >> price;
		std::cin.sync();
		std::cin.ignore();
		std::cin.clear();
		head = add_book(head, author, title, publication_date, price);
	}
	if (choice == 4)
	{
		write(head);
	}
	return head;
}

int user(struct data *head)
{
	std::cout << "Co chcesz zrobic?" << std::endl;
	std::cout << "1 - Dodac ksiazke" << std::endl;
	std::cout << "2 - Sprawdzic dostępnosc ksiazki" << std::endl;
	std::cout << "3 - Zmiejszyc ilosc ksiazek" << std::endl;
	std::cout << "4 - Sprawdzic aktualny stan ksiegarni" << std::endl;
	std::cout << "5 - Zakonczyc prace" << std::endl;


	std::string choice;
	unsigned int convert;
	while (true)
	{
		std::cout << std::endl;
		std::cout << "Wybierz opcje: " << std::endl;
		std::getline(std::cin, choice);
		convert = verification(choice);
		switch (convert)
		{
		case 0:
			break;
		case 1:	//Dodawanie książek
			head = user_switch(head, 1);
			break;

		case 2:	//Sprawdzaie dostępności książki, jej ceny itd.
			head = user_switch(head, 2);
			break;

		case 3:	//Zmiejszanie ilości książek (sprzedawanie)
			head = user_switch(head, 3);
			break;

		case 4:	//Aktualny stan księgarni
			head = user_switch(head, 4);
			break;

		case 5: //Zanończenie pracy
			return 0;
			break;

		default:
			std::cout << std::endl;
			std::cout << "Blad przy wpisywaniu danych" << std::endl;
			std::cout << "Wybierz inna opcje: " << std::endl;
			break;
		}
	}
}

int main()
{
	struct data *head = nullptr;
	

	std::fstream plik;
	plik.open("books.bin", std::ios::in | std::ios::out |std::ios::binary);
		if (plik.good()==false)
		{
			std::cout << "Nie znaleziono bazy. Tworze nowa" << std::endl;
		}
		else
		{
			
		}

		user(head);
		


    return 0;
}

