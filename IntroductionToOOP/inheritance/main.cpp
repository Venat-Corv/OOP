#include <iostream>
#include <string>
using namespace std;

#define delimiter "\n----------------------\n"

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

	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//Methods:
	virtual void info()
	{
		cout << last_name << " " << first_name << " " << age << " ���.\n";
	}
};

ostream& operator<<(ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " ���.\n";
}

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

ostream& operator<<(ostream& os, const Student& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " ���.\n" << 
		obj.get_specialty() << " " << obj.get_group() << " " << obj.get_year() << " ����, ������������ " << obj.get_rating() << endl;
}

class Teacher :public Human
{
	string faculty; // �����������
	unsigned int hours; // ����
	unsigned int qt_groups; // ���������� �����
	unsigned int experience; // ����
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
	unsigned int get_experience() const
	{
		return this->experience;
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
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//Constructors:
	Teacher(const string& first_name, const string& last_name, unsigned int age,
		const string& faculty, unsigned int qt_groups, unsigned int hours, unsigned int experience) :Human(first_name, last_name, age)
	{
		this->faculty = faculty;
		this->qt_groups = qt_groups;
		this->hours = hours;
		this->experience = experience;
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
		cout << faculty << " " << hours << " �����, ����� ����: " << experience << " ���/�" <<endl;
	}
};

ostream& operator<<(ostream& os, const Teacher& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " ���.\n" <<
		obj.get_faculty() << " " << obj.get_hours() << " �����, ����� ����: " << obj.get_experience() << " ���/�" << endl;
}

class Graduate :public Student
{
	string dyp_name; // ���� ���������
	unsigned int done_exam; // ������� ��������
	unsigned int tails; // ������)
public:
	const string& get_dyp_name() const
	{
		return this->dyp_name;
	}
	unsigned int get_done_exam() const
	{
		return this->done_exam;
	}
	unsigned int get_tails() const
	{
		return this->tails;
	}
	void set_dyp_name(const string& dyp_name)
	{
		this->dyp_name = dyp_name;
	}
	void set_done_exam(unsigned int done_exam)
	{
		this->done_exam = done_exam;
	}
	void set_tails(unsigned int tails)
	{
		this->tails = tails;
	}

	//Constructors
	Graduate(const string& first_name, const string& last_name, unsigned int age,
		const string& specialty, const string& group, unsigned int year, unsigned int rating,
		unsigned int done_exam, unsigned int tails, const string& dyp_name) :Student(first_name, last_name, age, specialty, group, year, rating)
	{
		this->done_exam = done_exam;
		this->tails = tails;
		this->dyp_name = dyp_name;
		cout << "GConstructor\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor\t" << this << endl;
	}

	//Methods:
	void info()
	{
		Student::info();
		cout << "���� �������: " << done_exam << " ������: " << tails << " \nT��� ��������� ������: " << dyp_name <<endl;
	}
};

ostream& operator<<(ostream& os, const Graduate& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " ���.\n" <<
		obj.get_specialty() << " " << obj.get_group() << " " << obj.get_year() << " ����, ������������ " << obj.get_rating() << endl <<
		"���� �������: " << obj.get_done_exam() << " ������: " << obj.get_tails() << " \nT��� ��������� ������: " << obj.get_dyp_name() << endl;
}

void main()
{
	setlocale(LC_ALL, "");
	/*Human h("�������", "�����", 21);
	h.info();
	Student s("����", "�������", 18, "���������", "�� �� 34�", 1, 0);
	s.info();
	Teacher t("��������", "����������", 45, "1�", 6, 1000, 3);
	t.info();
	Graduate g("�����", "�����", 19, "���������", "�� �� 34�", 3, 3400, 1, 49,
			   "\"������������ ������������� ���������: ����� � ������\"");
	g.info();

	Human* pt = &t;
	Human* pg = &g;
	cout << "\n------------------------\n";
	pt->info();
	pg->info();
	Human(*pt).info();
	Human(*pg).info();
	cout << "\n------------------------\n";*/
	Human* group[] =
	{
		new Graduate("�������", "������", 20, "���", "�� �� 34�", 1, 100, 10, 10, "������������ �������������� ���������: ����� � ������"),
		new Student("����", "��������", 18, "���", "�� �� 34�", 1, 70),
		new Teacher("������", "�����������", 40, "HardwarePC", 4, 200, 18),
		new Student("�������", "������", 18, "���", "�� �� 34�", 1, 70),
		new Graduate("��������", "����������", 17, "���", "�� �� 34�", 1, 80, 12, 8, "��� ����������� ���� ���� ��� �� ���� ��������"),
		new Teacher("�����", "�������", 30, "WebDev", 6, 160, 5)
	};
	
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << delimiter << endl;
		cout << typeid(*group[i]).name() << endl;
		cout << *group[i] << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
}