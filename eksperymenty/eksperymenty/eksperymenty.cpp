// eksperymenty.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

unsigned int verification(std::string choise)
{
	int charakters = choise.length();

	if (charakters == 1)
	{
		charakters = atoi(choise.c_str());
		return charakters;
	}
	else
		return 6;

	return 0;
}

int main()
{
	std::string choice;
	unsigned int convert;
	while (true)
	{
		std::cout << "Wybierz opcje: " << std::endl;
		std::getline(std::cin, choice);
		convert = verification(choice);
	}
	return 0;

}

