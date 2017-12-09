#include "Functions.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void check()
{
	std::ifstream plik;
	plik.open("data.txt");
	if (!plik.good())
	{
		plik.close();
		std::ofstream plik;
		plik.open("data.txt");
		cout << "Tworze nowa baze \"data.txt\"" << endl;
		plik << endl;
		plik.close();
	}
	else
		plik.close();
}

void add_book()
{
	check();
	std::ofstream plik;
	plik.open("data.txt", std::ios::ate);
	string title;
	string author;
	struct date;
	{
		unsigned int day;
		unsigned int month;
		unsigned int year;
	}
	unsigned int price;

	cout << "Podaj tytul:" << endl;
	std::getline(cin, title);
	cout << "Podaj autora:" << endl;

	cout << "Podaj date:" << endl;

	cout << "Podaj cenê:" << endl;



}

int reachability()
{

	return 0;
}

int amount()
{

	return 0;
}

int wpisz()
{
	string date;
	int choise;
	getline(cin, date);
	int length = date.length();

	if (length != 1)
	{
		return 0;
	}
	else
	{
		if (date[0] == '1' || date[0] == '2' || date[0] == '3' || date[0] == '4' || date[0] == '5')
		{
			choise = atoi(date.c_str());
			return choise;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}