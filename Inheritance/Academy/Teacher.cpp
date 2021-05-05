#include"Teacher.h"

const string& Teacher::get_speciality()const
{
	return speciality;
}
unsigned int Teacher::get_experience()const
{
	return experience;
}
void Teacher::set_speciality(const string& speciality)
{
	this->speciality = speciality;
}
void Teacher::set_experience(unsigned int experience)
{
	this->experience = experience;
}
//			Constructurs:
Teacher::Teacher
(
	human_take_parameters,
	teacher_get_parameters
) :Human(human_give_parameters)
{
	set_speciality(speciality);
	set_experience(experience);
	cout << "TConstructor:\t" << this << endl;
}
Teacher::~Teacher()
{
	cout << "TDestructor:\t" << this << endl;
}

//			Methods:
void Teacher::info()const
{
	Human::info();
	cout << speciality << ", опыт преподавания " << experience << " лет." << endl;
}

ostream& operator<<(ostream& os, const Teacher& obj)
{
	return os << (Human)obj << ", " << obj.get_speciality() << " опыт преподования " << obj.get_experience() << " лет";
}