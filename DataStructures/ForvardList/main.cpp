#include"ClassDeclaration.h"

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (ForwardList::Iterator it = right.begin(); it != right.end(); it++)
		cat.push_back(*it);
	return cat;
}

void main()
{
	setlocale(LC_ALL, "");
	int n;		//���������� ���������
	//cout << "������� ���������� ���������: ";	cin >> n;
#ifdef BASE_CHECK
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_front(rand() % 100);
	}
	fl.print();
	fl.push_back(123);	fl.print();
	fl.pop_back();	fl.print();

	int index;
	int data;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> data;
	fl.insert(index, data);
	fl.print();

	cout << "������� ������ ����������� ��������: "; cin >> index;
	fl.erase(index);
	fl.print();

	/*ForwardList fl2;
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(8);
	fl2.print();*/
#endif // BASE_CHECK

#ifdef INDEX_OPERATOR_CHECK
	//TODO: exception handling in []
	ForwardList fl(n);
	fl.print();

	cout << int() << endl;
	for (int i = 0; i < fl.get_size(); i++)
	{
		fl[i] = rand() % 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << fl[i] << tab;
	}
	cout << endl;
#endif // INDEX_OPERATOR_CHECK

#ifdef CONSTRUCTORS_CHECK
	ForwardList fl = { 3, 5, 8, 13, 21 };
	fl.print();
	fl = fl;
	fl.print();
#endif

	int Arr[] = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < sizeof(Arr) / sizeof(int); i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;

	for (int i : Arr)
	{
		cout << i << tab;
	}
	cout << endl;

	char str[] = "Hello";
	for (char i : str)
		cout << i << tab;
	cout << endl;
	ForwardList fl = { 666, 5, 8, 13, 21 };
	system("COLOR 0A");
	for (int i : fl)
	{
		cout << i << tab;
	}
	cout << endl;
	//cout << sizeof(ForwardList::Element) << endl;
	ForwardList fl2 = { 12, 33, 41 };
	ForwardList fl3;
	fl3 = fl + fl2;
	for (int i : fl3)
	{
		cout << i << endl;
	}
}