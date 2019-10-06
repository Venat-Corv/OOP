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
		pair<string, forward_list<Crime>>("BI6666BC", {Crime("��� �� ����" ,"������ � ������ ������� ������, � ���������� ���� ���� �������� ������ ������, � ������� �����")}),
		pair<string, forward_list<Crime>>("BI6667BC", {Crime("MacDonalds" ,"������ � ���� ���")}),
		pair<string, forward_list<Crime>>("BI1488CI", {Crime("��������� ����" ,"���� ����� ����� ������")})
	};

	do
	{
		bool exit = false;
		cout << "1. ����� ���� ����;" << endl;
		cout << "2. ����� ���������� �� ������;" << endl;
		cout << "3. ����� ���������� �� ��������� �������;" << endl;
		cout << "4. ��������� ������; " << endl;
		cout << "5. �����; " << endl;

		cout << "\n\n=============================\n\n";

		char key;
		cout << "�������� ��������: "; cin >> key;

		switch (key)
		{
		case '1': print(database); break;
		case '2':
		{
			string id;
			cout << "������� ����� ����������: "; cin >> id;
			print(database, id);
		}
		break;
		case '3': cout << "������ ����� �������� ����������..." << endl; break;
		case '4':
		{
			string id;
			string plase;
			string crime;
			cout << "������� ����� ����������: "; 
			cin.sync();
			cin.get();
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			getline(cin, id);
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			cout << "������� ����� ������������: ";
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			getline(cin, plase);
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			cout << "������� �������� ���������: ";
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			getline(cin, crime);
			SetConsoleOutputCP(866);
			SetConsoleCP(866);
			if (!add(database, id, plase, crime))
			{
				cout << "����� ��� �������� � ����, ���������� ������������ ������ �������..." << endl;
			}
			else
			{
				cout << "����� ��� ���� � ����, ���������� ������������ ������ �������..." << endl;
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
			cout << "����� ������������: " << j.get_place() << "\n" << "���������: " << j.get_crime() << endl;
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
				cout << "����� ������������: " << j.get_place() << "\n" << "���������: " << j.get_crime() << endl;
			}
		}
	}
	if (!present_in_base) cout << "� ���� ��� ������ ������" << endl;
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