// eksperymenty.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct s
{
	int a;
	int b;
	struct s *next;
};

int main()
{
	fstream plik;
	plik.open("test.bin", ios::in || ios::out || ios::binary);

	struct s *pisz1 = new struct s;
	struct s *pisz2 = new struct s;
	struct s *czytaj;

	pisz2->a = 2;
	pisz2->b = 22;
	pisz1->a = 1;
	pisz1->b = 11;
	pisz1->next = pisz2;
	pisz2->next = nullptr;

	char*temp = new char[sizeof(s)];
	plik.write(temp, sizeof(s));

	temp = new char[sizeof(s)];
	plik.read(temp, sizeof(s));
	
	plik.close();

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
