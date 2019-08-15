#include <iostream>
#include <string>
using namespace std;

class Human
{
	string first_name;
	string last_name;
	unsigned int age;
public:
	const string& get_first_name() const
	{
		return this->first_name;
	}
	const string& get_last_name() const
	{
		return this->last_name;
	}
	unsigned int get_age() const
	{
		return this->age;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//Constructors:
	Human(const string& first_name, const string& last_name, unsigned int age)
	{
		set_first_name(first_name);
		set_last_name(last_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}

	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//Methods:
	void info()
	{
		cout << last_name << " " << first_name << " " << age << " ���.\n";
	}
};

class Student :public Human
{
	string specialty;
	string group;
	unsigned int year; // ��� ��������
	unsigned int rating; // ������������
public:
	const string& get_specialty() const
	{
		return this->specialty;
	}
	const string& get_group() const
	{
		return this->group;
	}
	unsigned int get_year() const
	{
		return this->year;
	}
	unsigned int get_rating() const
	{
		return this->rating;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_year (unsigned int year)
	{
		this->year = year;
	}
	void set_rating(unsigned int rating)
	{
		this->rating = rating;
	}

	//Constructors:
	Student(const string& first_name, const string& last_name, unsigned int age,
		const string& specialty, const string& group, unsigned int year, unsigned int rating) : Human(first_name,last_name, age)
	{
		this->specialty = specialty;
		this->group = group;
		this->year = year;
		this->rating = rating;
		cout << "Sconstructor\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//Methods:
	void info()
	{
		Human::info();
		cout << specialty << " " << group << " " << year << " ����, ������������ " << rating << endl;
	}
};

class Teacher :public Human
{
	string faculty;
	unsigned int hours;
	unsigned int qt_groups;
public:
	const string& get_faculty() const
	{
		return this->faculty;
	}
	unsigned int get_hours() const
	{
		return this->hours;
	}
	unsigned int get_qt_groups() const
	{
		return this->qt_groups;
	}
	void set_faculty(const string& faculty)
	{
		this->faculty = faculty;
	}
	void set_hours(unsigned int hours)
	{
		this->hours = hours;
	}
	void set_qt_groups(unsigned int qt_groups)
	{
		this->qt_groups = qt_groups;
	}

	//Constructors:
	Teacher(const string& first_name, const string& last_name, unsigned int age, const string& faculty, unsigned int qt_groups, unsigned int hours) :Human(first_name, last_name, age)
	{
		this->faculty = faculty;
		this->qt_groups = qt_groups;
		this->hours = hours;
		cout << "TConstructor\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor\t" << this << endl;
	}

	//Methods:
	void info()
	{
		Human::info();
		cout << faculty << " " << hours << " �����" << endl;
	}
};

class Graduate :public Student
{
	unsigned int qt_exam;

};

void main()
{
	setlocale(LC_ALL, "");
	Human h("�������", "�����", 21);
	h.info();
	Student s("����", "�������", 18, "���������", "�� �� 34�", 1, 0);
	s.info();
}