#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	//time_t birth_date;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	const time_t get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age= age;
	}

	//             Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//              Methods:
	void info()const
	{
		/*cout << "Last name:\t" << last_name << endl;
		cout << "First_name:\t" << first_name << endl;
		cout << "Age:\t\t" << age << " years" << endl;*/
		cout << last_name << " " << first_name << ", " << age << " ���" << endl;
	}
};

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	//         Constructor:
	Student(
		const string& last_name, const string& first_name, unsigned int age,// �������� �������� ������
		const string& speciality, const string& group, double rating // �������� ������ ������
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDectructor" << this << endl;
	}
	//          Methods:
	void info()const
	{
		Human::info();
		cout << speciality << ", " << group << ", ������������: " << rating << endl;
	}
};

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//               Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,// �������� �������� ������
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//              Methods:
	void info()const
	{
		Human::info();
		cout << speciality << ", ���� ������������ " << experience << " ���." << endl;
	}
	
};

void main()
{
	setlocale(LC_ALL, "");
	/*Human human("�������", "�������", 18);
	human.info();*/
	Student vasya("�������", "�������", 18, "����������������", "BV011", 4.5);
	vasya.info();

	Teacher teacher("Einstein", "Albert", 150, "Phisics", 120);
	teacher.info();

}