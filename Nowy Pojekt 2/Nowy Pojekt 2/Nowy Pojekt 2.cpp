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
	
	if (element->author.compare(head->author) == 0)
	{
		help = head;
		while (head->down != nullptr)
		{
			head = help->down;
		}
		help->down = element;
		return head;
	}
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

struct data *delete_book(struct data *head)
{
	std::string author;
	std::string title;
	struct data *help;
	help = head;

	std::cout << "Podaj autora:" << std::endl;
	std::getline(std::cin, author);
	std::cout << "Podaj tytul:" << std::endl;
	std::getline(std::cin, title);
	
	while (help != nullptr)
	{
		if (help->author == author)
		{
			if (help->title == title)
			{
				if (help->down == nullptr)
				{
					if (help == head)
					{
						help->next->previous = nullptr;
						head = help->next;
						delete help;
						std::cout << "Ksiazka usunieta z bazy";
						return head;
					}

					if (help->next == nullptr)
					{
						help->previous->next = nullptr;
						delete help;
						std::cout << "Ksiazka usunieta z bazy";
						return head;
					}

					help->previous->next = help->next;
					help->next->previous = help->previous;
					delete help;
					std::cout << "Ksiazka usunieta z bazy";
					return head;
				}
				else
				{
					if (help == head)
					{
						help->next->previous = help->down;
						help->down->next = help->next;
						head = help->down;
						delete help;
						std::cout << "Ksiazka usunieta z bazy";
						return head;
					}

					if (help->next == nullptr)
					{
						help->previous->next = help->down;
						help->down->previous = help->previous;
						delete help;
						std::cout << "Ksiazka usunieta z bazy";
						return head;
					}

					help->previous->next = help->down;
					help->next->previous = help->down;
					help->down->next = help->next;
					help->down->previous = help->previous;
					delete help;

					std::cout << "Ksiazka usunieta z bazy";
					return head;
				}
			}
			else
			{
				while (help->down != nullptr)
				{
					if (help->down->title == title)
					{
						help->down = help->down->down;

						delete help;
						std::cout << "Ksiazka usunieta z bazy";
						return head;
					}
					help = help->down;
				}
				std::cout << "Brak tytulu." << std::endl;
				return head;
			}
		}
		help = help->next;
	}
	std::cout << "Brak autora." << std::endl;
	return head;
}

unsigned int verification(std::string choice) //sprawdza, czy użytkownik wpisał dobrą wartość
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

struct data *exchange(struct data *element, bool i)
{
	if (i)
	{
		for (int i = 0; i < element->author.length(); i++)
		{
			if (element->author[i] == ' ')
				element->author[i] = '_';
		}

		for (int i = 0; i < element->title.length(); i++)
		{
			if (element->title[i] == ' ')
				element->title[i] = '_';
		}
		return element;
	}
	else
	{
		for (int i = 0; i < element->author.length(); i++)
		{
			if (element->author[i] == '_')
				element->author[i] = ' ';
		}
		for (int i = 0; i < element->title.length(); i++)
		{
			if (element->title[i] == '_')
				element->title[i] = ' ';
		}
		return element;
	}

}

void end(struct data *head, int option)
{
	std::ofstream plik;
	plik.open("new.txt");
	if (option == 1)
	{
		while (head != nullptr)
		{
			if (head->down != nullptr)
			{
				struct data *help;
				help = head;
				std::cout << help->author << ":" << std::endl;
				while (help != nullptr)
				{
					std::cout << "\t\"" << help->title << "\" " << help->publication_date << "r. " << help->price << "zl" << std::endl;
					plik << help->author << " " << help->title << " " << help->publication_date << " " << help->price << " " << std::endl;
					help = help->down;
				}
			}
			else
			{
				std::cout << head->author << " \"" << head->title << "\" " << head->publication_date << "r. " << head->price << "zl" << std::endl;
				head = exchange(head, 1);
				plik << head->author << " " << head->title << " " << head->publication_date << " " << head->price << " " << std::endl;
			}
			head = head->next;
		}
	}
	else
	{
		while (head != nullptr)
		{
			if (head->down != nullptr)
			{
				struct data *help;
				help = head;
				while (help != nullptr)
				{
					plik << help->author << " " << help->title << " " << help->publication_date << " " << help->price << " " << std::endl;
					help = help->down;
				}
			}
			else
			{
				head = exchange(head, 1);
				plik << head->author << " " << head->title << " " << head->publication_date << " " << head->price << " " << std::endl;
			}
			head = head->next;
		}
	}
	
}

struct data *user_switch(struct data *head, int choice)
{
	if (choice == 1) //Dodac ksiazke
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
		return head;
	}
	//=================================================================================
	if (choice == 2) //Sprawdzic dostępnosc ksiazki
	{
		std::string name;
		struct data *help;
		help = head;

		std::cout << "Podaj autora ";
		std::getline(std::cin, name);

		while (help != nullptr)
		{
			if (help->author == name)
			{
				std::cout << "Dostepne ksiazki danego autora:" << std::endl;
				while (help != nullptr)
				{
					std::cout << help->title << std::endl;
					help = help->down;
				}
				return head;
			}
			help = help->next;
		}
		std::cout << "Brak autora." << std::endl;
		return head;
	}
	//================================================================================
	if (choice == 3) //Zmiejszyc ilosc ksiazek
	{
		head = delete_book(head);
		return head;
	}
	//========================================================================
	if (choice == 4) //Sprawdzic aktualny stan ksiegarni
	{
		end(head, 1);
		return head;
	}
}

int user(struct data *head)
{
	std::cout << "Co chcesz zrobic?" << std::endl;
	std::cout << "1 - Dodac ksiazke" << std::endl;
	std::cout << "2 - Sprawdzic dostępnosc ksiazki" << std::endl;
	std::cout << "3 - Zmiejszyc ilosc ksiazek" << std::endl;
	std::cout << "4 - Sprawdzic aktualny stan ksiegarni i zapisać wyniki" << std::endl;
	std::cout << "5 - Zakonczyc prace i zapisać wyniki" << std::endl;


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
			end(head, 2);
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

void load()
{
	struct data *head = nullptr;

	std::ifstream plik;
	plik.open("new.txt");
	if (plik.good() == false)
	{
		std::cout << "Nie znaleziono bazy. Tworze nowa." << std::endl;
		user(head);
	}
	else
	{
		std::cout << "Wczytuje baze z pliku" << std::endl;
		std::string author;
		std::string title;
		unsigned int publication_date;
		double price;
		struct data *help;
		help = nullptr;

		while (!plik.eof())
		{
			struct data *element;
			element = new struct data;
			element->next = nullptr;
			element->previous = nullptr;
			element->down = nullptr;
			plik >> element->author >> element->title >> element->publication_date >> element->price;
			if (element->author == "" || element->author == "\n")
			{
				continue;
			}

			if (help == nullptr)
			{
				help = element;
				head = help;
				continue;
			}

			if (element->author == help->author)
			{
				while (help->down != nullptr)
				{
					help = help->down;
				}
				help->down = element;
			}
			else
			{
				element->previous = help;
				element->previous->next = element;
			}
			help = element;
			element = exchange(element, 0);
		}
		std::cout << std::endl << "Rozpoczynam prace" << std::endl;
		user(head);
	}
}

int main()
{
	load();
    return 0;
}

