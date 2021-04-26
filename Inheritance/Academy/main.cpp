#include<iostream>
#include<string>
#include<ctime>
using namespace std;

#define delimiter "------------------------------------------------------------------------\t"
#define human_take_parameters   const string& last_name, const string& first_name, unsigned int age
#define student_get_parameters const string& speciality, const string& group, double rating
#define teacher_get_parameters const string& speciality, unsigned int experience

#define human_give_parameters   last_name, first_name, age
#define student_give_parameters speciality, group, rating
#define teacher_give_parameters speciality, experience

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
		cout << last_name << " " << first_name << ", " << age << " лет" << endl;
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
		human_take_parameters,// Атрибуты базового класса
		student_get_parameters // Атрибуты нашего класса
	):Human(human_give_parameters)
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
		cout << speciality << ", " << group << ", успеваемость: " << rating << endl;
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
		human_take_parameters,
		teacher_get_parameters
	) :Human(human_give_parameters)
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
		cout << speciality << ", опыт преподавания " << experience << " лет." << endl;
	}
	
};

class Graduate: Student
{
	string issue;              //Тема дипломной работы
	unsigned int project_size; // Размер работы
public:
	const string& get_issue()const
	{
		return issue;
	}
	unsigned int get_project_size()const
	{
		return project_size;
	}
	void set_issue(const string& issue)
	{
		this->issue = issue;
	}
	void set_project_size(unsigned int project_size)
	{
		this->project_size = project_size;
	}
	//         Constructor:
	Graduate
	(
		human_take_parameters,
		student_get_parameters,
		const string& issue, unsigned int project_size
	):Student(human_give_parameters, student_give_parameters)
	{
		set_issue(issue);
		set_project_size(project_size);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void info()const
	{
		Student::info();
		cout << "Тема дипломной работы: " << issue << ", размер работы: " << project_size << " страниц" << endl;
	}

};

//#define intheritence_check


void main()
{
#ifdef inheritence_check
	setlocale(LC_ALL, "");
	/*Human human("Тупенко", "Василий", 18);
	human.info();*/
	Student vasya("Тупенко", "Василий", 18, "Программирование", "BV011", 4.5);
	vasya.info();
	cout << delimiter << endl;
	Teacher teacher("Einstein", "Albert", 150, "Phisics", 120);
	teacher.info();
	cout << delimiter << endl;
	Graduate Dima(
		"Тупенко", "Дмитрий", 18,
		"Программирование", "BV011", 4.5,
		"Программирование на C++", 25);
	Dima.info();
	cout << delimiter << endl;
#endif // inheritence_check

}