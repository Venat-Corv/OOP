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
		pair<string, forward_list<Crime>>("BI6666BC", {Crime("��� �� ����" ,"������ � ������ ������� ������, � ���������� ���� ���� �������� ������ ������, � ������� �����")}),
		pair<string, forward_list<Crime>>("BI6667BC", {Crime("MacDonalds" ,"������ � ���� ���")}),
		pair<string, forward_list<Crime>>("BI1488CI", {Crime("��������� ����" ,"���� ����� ����� ������")})
	};


	cout << "1. ����� ���� ����;" << endl;
	cout << "2. ����� ���������� �� ������;" << endl;
	cout << "3. ����� ���������� �� ��������� �������;" << endl;
	cout << "4.��������� ������; " << endl;
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