#pragma once
#include <iostream>
using namespace std;

#define tab "\t"

class Fraction;//Обьявление класса
Fraction operator+(Fraction left, Fraction right);//Прототип оператора +
Fraction operator-(Fraction left, Fraction right);//Прототип оператора -
Fraction operator*(Fraction left, Fraction right);//Прототип оператора *
Fraction operator/(Fraction left, Fraction right);//Прототип оператора /
class Fraction
{
	bool minus;//нужно реализовать
	int integer;    //целая часть
	int numerator;  //Числитель
	int denominator;//Знаменатель
public:
	bool get_minus()const;
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_minus(bool minus);
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	////////////////////////////////////////
	Fraction& set_minus_to_number();
	Fraction& get_minus_from_number();
	/////////////////////////////////////////

	//         Constructors:
	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	~Fraction();
	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	//         increment/decrement
	Fraction& operator++();
	Fraction operator++(int);
	//          Type cast operators:
	explicit operator int() const;
	explicit operator double() const;
	//         Methods:
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction& reduce();
};