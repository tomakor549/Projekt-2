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


void add_book(std::fstream &plik)
{
	plik.open("data.txt", std::ios::ate | std::ios::app);
	if (!plik.good())
	{
		plik.close();
		cout << "Tworze nowa baze \"data.txt\"" << endl;
		std::ofstream plik;
		plik.open("data.txt");
	}

	string title;
	string author;
	bool repeat = true;
		unsigned int day;
		unsigned int month;
		unsigned int year;
	float price;

	cout << "Podaj tytul:" << endl;
	std::getline(cin, title);
	cout << "Podaj autora:" << endl;
	std::getline(cin, author);
	cout << "Podaj date wydania:" << endl;

	cout << "dzien: ";
	while (repeat)
	{
		cin >> day;
		if (day > 31)
		{
			cout << "Zly dzien, sproboj jeszcze raz." << endl;
		}
		else
		{
			repeat = false;
		}
	}
	repeat = true;

	cout << "miesiac: ";
	while (repeat)
	{
		cin >> month;
		if (month > 12)
		{
			cout << "Zly miesiac, sproboj jeszcze raz." << endl;
		}
		else
		{
			repeat = false;
		}
	}
	repeat = true;
	cout << "rok: ";
	while (repeat)
	{
		cin >> year;
		if (year > 2017)
		{
			cout << "Zly rok, sproboj jeszcze raz." << endl;
		}
		else
		{
			repeat = false;
		}
	}
	repeat = true;

	cout << "Podaj cene:" << endl;
	cin >> price;

	plik << title << "\t" << author << "\t" << day << "-" << month << "-" << year << "\t" << price << "zl"<< endl;
	plik.close();
}

int reachability()
{

	return 0;
}

int amount()
{

	return 0;
}

int wpisz(string date)
{

	int length = date.length();

	if (length > 1)
	{
		return 6;
	}
	else
	{
		if (date[0] == '1' || date[0] == '2' || date[0] == '3' || date[0] == '4' || date[0] == '5')
		{
			int i = atoi(date.c_str());
			return i;
		}
		else
			return 0;
	}
}