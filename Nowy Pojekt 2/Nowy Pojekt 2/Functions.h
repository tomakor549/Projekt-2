#pragma once
// Nowy Pojekt 2.cpp : Defines the entry point for the console application.
//
/*Ksi�garnia � Baza danych dla ksi�garni. W programie powinna istnie� mo�liwo�� dodania
nowej ksi��ki (tytu�, rok wydania, autor, cena), sprawdzenia dost�pno�ci ksi��ki, ceny itd. Liczba
dost�pnych egzemplarzy powinna odzwierciedla� aktualny stan ksi�garni (np. po sprzeda�y). Baza
powinna by� serializowana do pliku*/

#include "stdafx.h"
#include <iostream>
#include <string>

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

struct data *exchange0(struct data *element, bool i);

unsigned int verification(std::string choice);

struct data *add_book(struct data *head, std::string author, std::string title, unsigned int publication_date, double price);

void check_title(struct data *head, std::string name);

struct data *delete_book(struct data *head);

void file_and_console(struct data *head);

void save_file(struct data *head);

unsigned int taste_publication_date();

struct data *user_switch(struct data *head, int choice);

void user(struct data *head);

void load();

