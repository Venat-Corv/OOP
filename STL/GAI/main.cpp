#include <iostream>
#include <string>
#include <map>
#include <forward_list>

#include "Crime.h"

using namespace std;

void print(const map<string, forward_list<Crime>>& database);
void print(const map<string, forward_list<Crime>>& database, const string& id);

void main()
{
	setlocale(LC_ALL, "");
	map<string, forward_list<Crime>> database =
	{
		pair<string, forward_list<Crime>>("BI6666BC", {Crime("АТБ на Ляли" ,"Принес в жертву черного барана, в результате чего олил светофор кровью барана, и заляпал зебру")}),
		pair<string, forward_list<Crime>>("BI6667BC", {Crime("MacDonalds" ,"Плюнул в пост ГАИ")}),
		pair<string, forward_list<Crime>>("BI1488CI", {Crime("Корпусный парк" ,"Сбил забор возле клумбы")})
	};


	cout << "1. Вывод всей базы;" << endl;
	cout << "2. Вывод информации по номеру;" << endl;
	cout << "3. Вывод информации по диапазону номеров;" << endl;
	cout << "4.Добавляем записи; " << endl;
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

	}
	//print(database);

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