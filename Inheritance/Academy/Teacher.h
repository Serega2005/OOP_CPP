#pragma once
#include"Human.h"

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const;
	unsigned int get_experience()const;
	void set_speciality(const string& speciality);
	void set_experience(unsigned int experience);
	//               Constructors:
	Teacher
	(
		human_take_parameters,
		teacher_get_parameters
	);
	~Teacher();
	//              Methods:
	void info()const;
};