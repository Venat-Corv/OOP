#include<iostream>
#include<string>
//Associative containers
#include<array>
#include<vector>
#include<deque>
#include<forward_list>
#include<list>
//Associative container
#include<map>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define STL_ARRAY
#define STL_VECTOR
//#define STL_DEQUE
//#define STL_FORVARD_LIST
//#define STL_LIST
//#define STL_MAP

#define tab "\t"
#define delimiter "\n------------------------\n"

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	int Arr[] = { 3, 5, 8, 13, 21 };
	array<int, 5> arr = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	for (int i : Arr)
	{
		cout << i << "\t";
	}
	cout << endl;

	/*int* d_arr = new int[5]{ 34,88,123 };
	for (int i : d_arr)
	{
		cout << i << "\t";
	}
	cout << endl;
	delete[] d_arr;*/

	for (int i : arr) cout << i << "\t"; cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	vector<int> vec = {0,1,1,2,3,5,8,13,21,34};
	try
	{
		for (int i = 0; i < vec.size() * 2; i++)
		{
			cout << vec.at(i) << "\t";
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;

	vec.push_back(55);
	vec.push_back(89);

	for (vector<int>::iterator it = vec.begin(); it != vec.end();it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	for (vector<int>::iterator it = vec.end()-1; /*it != vec.begin()*/; it--)
	{
		cout << *it << "\t";
		if (it == vec.begin())break;
	}
	cout << endl;
	vec.resize(8);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	vec.shrink_to_fit();

	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	cout << vec.empty() << endl;
	vec.reserve(15);
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	int* vec_arr = vec.data();

	int index;
	int data;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> data;
	vec.insert(vec.begin() + index, 3 ,data);
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	cout << "¬ведите индекс удал€емого Їлемента: "; cin >> index;
	vec.erase(vec.begin() + index);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	int start, finish;
	cout << "¬ведите индекс начала удалени€: "; cin >> start;
	cout << "¬ведите индекс конца удалени€: "; cin >> finish;
	vec.erase(vec.begin() + start, vec.begin() + finish);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	/*vec.assign(6, 100);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;*/
	vec.assign(vec.begin() + 2, vec.begin() + 5);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;


#endif // STL_VECTOR

#ifdef STL_DEQUE
	deque<int> dq = { 3,5,8,13,21 };
	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i] << "\t";
	}
	cout << endl;
	/*dq.push_back(34);
	dq.push_back(55);
	dq.push_front(0);
	dq.push_front(1);*/

	dq.insert(dq.begin(), {0,1,1});
	dq.insert(dq.end(), {34,55,89});
	//dq.insert()

	/*dq.emplace(dq.begin() + 3,  128, 256, 512);*/

	for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
#endif // STL_DEQUE

#ifdef STL_FORVARD_LIST
	forward_list<int> fl{3,5,8,13,21};
	for (int i : fl)cout << i << "\t"; cout << endl;
	cout << fl.max_size() << endl;

	for (forward_list<int>::iterator it = fl.begin(); it != fl.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;

	fl.insert_after(fl.before_begin(), { 0,1,1,2 });

	for (forward_list<int>::iterator it = fl.begin(); it != fl.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;

	int index;
	int data;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> data;

	int i = 0;
	for (forward_list<int>::iterator it = fl.begin(); it != fl.end(); it++)
	{
		if (i == index-1)
		{
			fl.insert_after(it, data);
			break;
		}
		i++;
	}

	for (forward_list<int>::iterator it = fl.begin(); it != fl.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
#endif // STL_FORVARD_LIST

#ifdef STL_LIST
	/*list<int> my_list{3,5,8,13,21};
	my_list.resize(8, 101);
	cout << my_list.size() << endl;
	cout << my_list.max_size() << endl;
	cout << forward_list<int>().max_size() << endl;
	for (int i : my_list)cout << i << "\t"; cout << endl;*/
	/*list<int> list1 = { 3,5,8,13,21 };
	list<int> list2 = { 34,55,89 };
	list<int>::iterator position = list2.begin();
	position++;
	list1.splice(list1.end(), list2, position);
	for (int i : list1)cout << i << "\t"; cout << endl;*/

	list<int> my_list(10);

	for (list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
	{
		*it = rand() % 10;
	}

	for (int i : my_list)
	{
		cout << i << "\t";
	}
	cout << endl;

	cout << "size:\t" << my_list.size() << endl;
	//my_list.remove(4);
	for (list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
	{
		my_list.remove_if([&it](int num)-> bool {return num % 2 == 0; });
	}
	for (int i : my_list)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif // STL_LIST

#ifdef STL_MAP
	map<int, string> week = 
	{
		pair<int, string>(0,"Sunday"),
		pair<int, string>(1,"Monday"),
		pair<int, string>(2,"Tuesday"),
		pair<int, string>(3,"Wednesday"),
		pair<int, string>(4,"Thursday"),
		pair<int, string>(5,"Friday"),
		pair<int, string>(6,"Saturday")
	};

	for (map<int, string>::iterator it = week.begin(); it != week.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	
	cout << delimiter << endl;

	for (pair<int, string>i : week)
	{
		cout << i.first << tab << i.second << endl;
	}

	cout << delimiter << endl;
#endif // STL_MAP
}