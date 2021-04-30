#include"Human.h"

const string& Human::get_last_name()const
{
	return last_name;
}
const string& Human::get_first_name()const
{
	return first_name;
}

void Human::set_last_name(const string& last_name)
{
	this->last_name = last_name;
}
void Human::set_first_name(const string& first_name)
{
	this->first_name = first_name;
}
void Human::set_age(unsigned int age)
{
	this->age = age;
}

//             Constructors:
Human::Human(const string& last_name, const string& first_name, unsigned int age)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	cout << "HConstructor:\t" << this << endl;
}
Human::~Human()
{
	cout << "HDestructor:\t" << this << endl;
}
//              Methods:
void Human::info()const
{
	/*cout << "Last name:\t" << last_name << endl;
	cout << "First_name:\t" << first_name << endl;
	cout << "Age:\t\t" << age << " years" << endl;*/
	cout << last_name << " " << first_name << ", " << age << " ���" << endl;
}