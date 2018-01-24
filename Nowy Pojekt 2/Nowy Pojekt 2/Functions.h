#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

struct data;

struct data *exchange(struct data *element, bool i);

unsigned int verification(std::string choice);

struct data *add_book(struct data *head, std::string author, std::string title, unsigned int publication_date, double price);

void check_title(struct data *head, std::string name);

struct data *delete_book(struct data *head);

void file_and_console(struct data *head);

void save_file(struct data *head);

struct data *user_switch(struct data *head, int choice);

void user(struct data *head);

void load();