#include"Student.h"

const string& Student::get_speciality()const
{
	return speciality;
}
const string& Student::get_group()const
{
	return group;
}
double Student::get_rating()const
{
	return rating;
}
void Student::set_speciality(const string& speciality)
{
	this->speciality = speciality;
}
void Student::set_group(const string& group)
{
	this->group = group;
}
void Student::set_rating(double rating)
{
	this->rating = rating;
}
//         Constructor:
Student::Student(
	human_take_parameters,// Атрибуты базового класса
	student_get_parameters // Атрибуты нашего класса
) :Human(human_give_parameters)
{
	set_speciality(speciality);
	set_group(group);
	set_rating(rating);
	cout << "SConstructor:\t" << this << endl;
}
Student::~Student()
{
	cout << "SDectructor:\t" << this << endl;
}
//          Methods:
void Student::info()const
{
	Human::info();
	cout << speciality << ", " << group << ", успеваемость: " << rating << endl;
}