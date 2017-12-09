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
void add_book()
{

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