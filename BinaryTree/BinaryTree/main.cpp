#include <iostream>
using namespace std;

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
		{
			this->Data = Data;
			this->pLeft = pLeft;
			this->pRight = pRight;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class Tree;
	} *Root;
public:
	Element* getRoot()
	{
		return this->Root;
	}

	Tree()
	{
		Root = nullptr;
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
		clear();
	}

	void insert(int Data)
	{
		insert(Data, this->Root);
	}

	int getMinValue()
	{
		return getMinValue(this->Root);
	}

	int getMinValue(Element* Root)
	{
		if (Root->pLeft == nullptr) return Root->Data;
		return getMinValue(Root->pLeft);
	}

	int getMaxValue()
	{
		return getMaxValue(this->Root);
	}

	int getMaxValue(Element* Root)
	{
		if (Root->pRight == nullptr) return Root->Data;
		return getMaxValue(Root->pRight);
	}

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr) return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)
			{
				Root->pLeft = new Element(Data);
			}
			else
			{
				insert(Data, Root->pLeft);
			}
		}
		else if(Data > Root->Data)
		{
			if (Root->pRight == nullptr)
			{
				Root->pRight = new Element(Data);
			}
			else
			{
				insert(Data, Root->pRight);
			}
		}
	}

	void clear()
	{
		clear(this->Root);
		this->Root = nullptr;
	}

	void clear(Element* Root)
	{
		if (Root == nullptr) return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}

	void print()
	{
		print(this->Root);
		cout << endl;
	}

	void print(Element* Root)
	{
		if (Root == nullptr) return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}

	int count()
	{
		return count(this->Root);
	}

	int count(Element* Root)
	{
		if (Root == nullptr) return 0;
		return count(Root->pLeft) + count(Root->pRight) + 1;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ ������: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();
	cout << "����������� �������� � ������:\t " << tree.getMinValue() << endl;
	cout << "������������ �������� � ������:\t " << tree.getMaxValue() << endl;
	cout << "���������� ���������:\t " << tree.count() << "\t" << endl;
	tree.clear();
	tree.print();
}