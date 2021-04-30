#pragma once
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define delimiter "\n------------------------------------------------------------------------\n"
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
	const string& get_last_name()const;
	const string& get_first_name()const;
	const time_t get_age()const;
	void set_last_name(const string& last_name);
	void set_first_name(const string& first_name);
	void set_age(unsigned int age);

	//             Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age);
	virtual ~Human();
	//              Methods:
	virtual void info()const;
};