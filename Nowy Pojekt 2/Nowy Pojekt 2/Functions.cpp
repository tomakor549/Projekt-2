
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Functions.h"
//-
struct data *exchange0(struct data *element)
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
//-
std::string exchange_author(std::string author)
{
	for (int i = 0; i < author.length(); i++)
	{
		if (author[i] == ' ')
			author[i] = '_';
	}
	return author;
}
//-
std::string exchange_title(std::string title)
{
	for (int i = 0; i < title.length(); i++)
	{
		if (title[i] == ' ')
			title[i] = '_';
	}
	return title;
}
//-
unsigned int verification(std::string choice) //sprawdza, czy u�ytkownik wpisa� dobr� warto��
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
//-
struct data *add_book(struct data *head, std::string author, std::string title, unsigned int publication_date, double price)		//dodawanie ksi��ki
{
	//head z juz istniejacej listy, lub nowe = nullptr
	struct data *element;
	element = new struct data;
	element->author = author;
	element->title = title;
	element->publication_date = publication_date;
	element->price = price;
	element->next = nullptr;
	element->previous = nullptr;
	element->down = nullptr;
	if (head == nullptr)
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
	while (help != nullptr)
	{
		if (help->author.compare(element->author) == 0) //je�li autor z 'g�owy' jest taki sam jak autor z elementu
		{
			while (help->down != nullptr)
			{
				help = help->down;
			}
			help->down = element;
			break;
		}
		//je�li nie:

		if (help->next == nullptr)		//nie wykona�o powy�szych krok�w i si� zgadza
		{
			help->next = element;
			element->previous = help;
			break;
		}

		if (element->author.compare(help->next->author) < 0)
		{
			//Wykonuje je�li autor z elementu powinien by� przed autorem z pomocy (alfabetycznie od A-Z)
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
//-
void check_title(struct data *head, std::string name, std::string title)
{
	struct data *help;
	help = head;

	while (help != nullptr)
	{
		if (help->author == name)
		{
			while (help != nullptr)
			{
				if (help->title == title)
				{
					std::cout << "Ksiazka dostepna." << std::endl;
					return;
				}
				else
				{
					std::cout << "Brak tytulu." << std::endl;
					return;
				}

				help = help->down;
			}
			return;
		}
		help = help->next;
	}
	std::cout << "Brak autora." << std::endl;
}
//-
struct data *delete_book(struct data *head)
{
	std::string author;
	std::string title;
	struct data *help;
	help = head;

	if (help == nullptr)
	{
		std::cout << "Brak ksiazek do usuniecia." << std::endl;
		return head;
	}

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
						if (help->next == nullptr)
						{
							help->down->next = help->next;
							head = help->down;
							delete help;
							std::cout << "Ksiazka usunieta z bazy";
							return head;
						}

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
//-
void file_and_console(struct data *head)	//wczytuje na konsole i do pliku
{
	std::ofstream plik;
	plik.open("new.txt");


	std::string author;
	std::string title;
	std::cout << std::endl;
	std::cout <<"Dostepne ksiazki:"<< std::endl;

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
				author = exchange_author(help->author);
				title = exchange_title(help->title);
				plik << author << " " << title << " " << help->publication_date << " " << help->price << " " << std::endl;
				help = help->down;
			}
		}
		else
		{
			std::cout << head->author << " \"" << head->title << "\" " << head->publication_date << "r. " << head->price << "zl" << std::endl;
			author = exchange_author(head->author);
			title = exchange_title(head->title);
			plik << author << " " << title << " " << head->publication_date << " " << head->price << " " << std::endl;
		}
		head = head->next;
	}
	plik.close();
}
//-
void delete_list(struct data *head)
{
	struct data *help1;
	struct data *help2;

	while (head != nullptr)
	{
		if (head->down != nullptr)
		{
			help1 = head->down;
			while (help1 != nullptr)
			{
				help2 = help1;
				help1 = help1->down;
				delete help2;
			}
			delete help1;
		}
		help2 = head;
		head = head->next;
		delete help2;
	}
	delete head;
}
//-
void save_file(struct data *head)	//wczytuje do pliku
{
	std::ofstream plik;
	plik.open("new.txt");
	std::string author;
	std::string title;
	struct data *start;
	start = head;

	while (head != nullptr)
	{
		if (head->down != nullptr)
		{
			struct data *help;
			help = head;
			while (help != nullptr)
			{
				author = exchange_author(help->author);
				title = exchange_title(help->title);
				plik << author << " " << title << " " << help->publication_date << " " << help->price << " " << std::endl;
				help = help->down;
			}
		}
		else
		{
			author = exchange_author(head->author);
			title = exchange_title(head->title);
			plik << author << " " << title << " " << head->publication_date << " " << head->price << " " << std::endl;
		}
		head = head->next;
	}
	plik.close();

	delete_list(start);
}

unsigned int taste_publication_date()
{
	std::string publication_date;
	unsigned int date;
	int l;

	while (true)
	{
		std::cout << "Wypisz date(rok) wydania:" << std::endl;
		getline(std::cin, publication_date);
		l = publication_date.length();
		if (l != 4)
		{
			std::cout << "Cos zle wpisano, sprobuj jeszcze raz." << std::endl;
			continue;
		}
		date = atoi(publication_date.c_str());
		if (date <= 2018 && date >= 1900)
		{
			return date;
		}
		else
			std::cout << "Cos zle wpisano, sprobuj jeszcze raz." << std::endl;
	}
	
}

double taste_price()
{
	std::string money;
	double price;
	int l;

	int i;
	int dot;
	int count;
	bool good;

	while (true)
	{
		dot = 0;
		count = 0;
		good = true;

		std::cout << "Wypisz cene:" << std::endl;
		getline(std::cin, money);
		l = money.length();
		
		for (i = 0; i < l; i++)
		{
			if (count != 0)
				count++;

			if (money[i] == '.')
			{
				if (i == 0 || i == l)
					good = false;
				dot++;
				count++;
			}
			else
				if (money[i]<'0' || money[i]>'9')
					good = false;
		}

		if (dot > 1)
			good = false;

		if (count > 3)
			good = false;

		if (good == false)
		{
			std::cout << "Zla cena, sprobuj raz jeszcze." << std::endl;
			std::cout << std::endl;
			continue;
		}

		break;
	}

	price = std::stod(money);
	return price;
}
//-
struct data *user_switch(struct data *head, int choice)
{
	if (choice == 1) //Dodac ksiazke
	{
		std::string author;
		std::string title;
		unsigned int publication_date;
		double price;
		std::cout << "Wypisz autora:" << std::endl;
		getline(std::cin, author);					
		
		std::cout << "Wypisz tytul:" << std::endl;
		getline(std::cin, title);					
		
		publication_date = taste_publication_date();
		
		price = taste_price();

		head = add_book(head, author, title, publication_date, price);
		return head;
	}
	//=================================================================================
	if (choice == 2) //Sprawdzic dost�pnosc ksiazki
	{
		std::string name;
		std::string title;
		struct data *help;
		help = head;

		std::cout << std::endl;
		std::cout << "Podaj autora: ";
		std::getline(std::cin, name);
		std::cout << "Podaj tytul: ";
		std::getline(std::cin, title);

		check_title(head, name, title);

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
		file_and_console(head);
		return head;
	}
	return head;
}//
//-
void user(struct data *head)
{
	std::cout << "Co chcesz zrobic?" << std::endl;
	std::cout << "1 - Dodac ksiazke" << std::endl;
	std::cout << "2 - Sprawdzic dostepnosc ksiazki" << std::endl;
	std::cout << "3 - Zmiejszyc ilosc ksiazek" << std::endl;
	std::cout << "4 - Sprawdzic aktualny stan ksiegarni i zapisac wyniki" << std::endl;
	std::cout << "5 - Zakonczyc prace i zapisac wyniki" << std::endl;


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
		case 1:	//Dodawanie ksi��ek
			head = user_switch(head, 1);
			break;

		case 2:	//Sprawdzaie dost�pno�ci ksi��ki, jej ceny itd.
			head = user_switch(head, 2);
			break;

		case 3:	//Zmiejszanie ilo�ci ksi��ek (sprzedawanie)
			head = user_switch(head, 3);
			break;

		case 4:	//Aktualny stan ksi�garni
			head = user_switch(head, 4);
			break;

		case 5: //Zano�czenie pracy
			save_file(head);
			return;
			break;

		default:
			std::cout << std::endl;
			std::cout << "Blad przy wpisywaniu danych" << std::endl;
			std::cout << "Wybierz inna opcje: " << std::endl;
			break;
		}
	}
}//
//-
void load(std::string wczytaj)
{
	struct data *head = nullptr;

	std::ifstream plik;
	plik.open(wczytaj);
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
				head = exchange0(element);
				help = head;
				continue;
			}

			if (element->author == help->author)
			{
				while (help->down != nullptr)
				{
					help = help->down;
				}
				help->down = exchange0(element);
			}
			else
			{
				element->previous = help;
				element->previous->next = exchange0(element);
			}
			element = exchange0(element);
			help = element;
		}
		std::cout << std::endl << "Rozpoczynam prace" << std::endl;
		user(head);
	}
	plik.close();
}//
