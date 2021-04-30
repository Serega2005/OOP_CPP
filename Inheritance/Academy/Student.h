#pragma once
#include"Human.h"

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const;
	const string& get_group()const;
	double get_rating()const;
	void set_speciality(const string& speciality);
	void set_group(const string& group);
	void set_rating(double rating);
	//         Constructor:
	Student(human_take_parameters,student_get_parameters);
	~Student();
	//          Methods:
	void info()const;
};