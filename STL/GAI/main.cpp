#include <iostream>
#include <string>
#include <map>
#include <forward_list>
#include<Windows.h>

#include "Crime.h"

using namespace std;

void print(const map<string, forward_list<Crime>>& database);
void print(const map<string, forward_list<Crime>>& database, const string& id);
bool add(map<string, forward_list<Crime>>& database, const string& id, const string& plase, const string& crime);

void main()
{
	setlocale(LC_ALL, "");
	map<string, forward_list<Crime>> database =
	{
		pair<string, forward_list<Crime>>("BI6666BC", {Crime("АТБ на Ляли" ,"Принес в жертву черного барана, в результате чего олил светофор кровью барана, и заляпал зебру")}),
		pair<string, forward_list<Crime>>("BI6667BC", {Crime("MacDonalds" ,"Плюнул в пост ГАИ")}),
		pair<string, forward_list<Crime>>("BI1488CI", {Crime("Корпусный парк" ,"Сбил забор возле клумбы")})
	};

	do
	{
		bool exit = false;
		cout << "1. Вывод всей базы;" << endl;
		cout << "2. Вывод информации по номеру;" << endl;
		cout << "3. Вывод информации по диапазону номеров;" << endl;
		cout << "4. Добавляем записи; " << endl;
		cout << "5. Выход; " << endl;

		cout << "\n\n=============================\n\n";

		char key;
		cout << "Выбирите действие: "; cin >> key;

		switch (key)
		{
		case '1': print(database); break;
		case '2':
		{
			string id;
			cout << "Введите номер автомобиля: "; cin >> id;
			print(database, id);
		}
		break;
		case '3': cout << "Данный пункт временно недоступен..." << endl; break;
		case '4':
		{
			string id;
			string plase;
			string crime;
			cout << "Введите номер автомобиля: "; 
			cin.sync();
			cin.get();
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			getline(cin, id);
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			cout << "Введите место происшествия: ";
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			getline(cin, plase);
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			cout << "Введите описание нарушения: ";
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			getline(cin, crime);
			SetConsoleOutputCP(866);
			SetConsoleCP(866);
			if (!add(database, id, plase, crime))
			{
				cout << "Номер был добавлен в базу, добавление происшествия прошло успешно..." << endl;
			}
			else
			{
				cout << "Номер уже есть в базе, добавление происшествия прошло успешно..." << endl;
			}
			break;
		}
		case '5': exit = true; break;
		}
		cout << "\n\n=============================\n\n";
	} while (exit);
}

void print(const map<string, forward_list<Crime>>& database)
{
	for (pair<string, forward_list<Crime>> i : database)
	{
		cout  << i.first << ":\n";
		for (Crime j : i.second)
		{
			cout << "Место происшествия: " << j.get_place() << "\n" << "Нарушение: " << j.get_crime() << endl;
		}
	}
}

void print(const map<string, forward_list<Crime>>& database, const string& id)
{
	bool present_in_base = false;
	for (pair<string, forward_list<Crime>>i : database)
	{
		if (id == i.first)
		{
			present_in_base = true;
			for (Crime j : i.second)
			{
				cout << "Место происшествия: " << j.get_place() << "\n" << "Нарушение: " << j.get_crime() << endl;
			}
		}
	}
	if (!present_in_base) cout << "В базе нет такого номера" << endl;
}

bool add(map<string, forward_list<Crime>>& database, const string& id, const string& plase, const string& crime)
{
	bool present_in_base = false;
	for (pair<string, forward_list<Crime>>i : database)
	{
		if (id == i.first)
		{
			present_in_base = true;
			i.second.push_front(Crime(plase, crime));
		}
	}
	if (!present_in_base)
	{
		database.insert(pair<string, forward_list<Crime>>(id, { Crime(plase, crime) }));
	}
	return present_in_base;
}