// eksperymenty.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{

	return 0;
}






/*
struct dane
{
	int name;
	struct dane *next;
};

int main()
{
	ofstream plik;
	plik.open("test.bin", ios::binary);
	
	struct dane *dane;
	struct dane *head;

	dane = new struct dane;
	dane->name=3;
	dane->next = nullptr;
	head = dane;

	dane = new struct dane;
	dane->name = 2;
	dane->next = head;
	head = dane;

	dane = new struct dane;
	dane->name = 1;
	dane->next = head;
	head = dane;


	plik.write((char *)& dane, sizeof dane);
	delete dane;
	plik.close();

	ifstream plik;
	plik.open("test.bin", ios::binary);

	if (!plik.good())
	{
		return 0;
	}
	struct dane *dane1;
	plik.read((char *)& dane1, sizeof dane1);
	cout << dane1->name << " ";

	plik.close();

	return 0;
}
*/
