#include"Fraction.h"

bool Fraction::get_minus()const
{
	return minus;
}
int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_minus(bool minus)
{
	this->minus = minus;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
////////////////////////////////////////
Fraction& Fraction::set_minus_to_number()
{
	if (minus)
	{
		integer = -integer;
		numerator = -numerator;
		minus = false;
	}
	return *this;
}
Fraction& Fraction::get_minus_from_number()
{
	if (integer < 0)
	{
		integer = -integer;
		minus = true;
	}
	if (numerator < 0)
	{
		numerator = -numerator;
		minus = true;
	}
	return *this;
}
/////////////////////////////////////////

//         Constructors:
Fraction::Fraction()
{
	this->minus = false;
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "Constructor0:\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->minus = false;
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	if (integer < 0)
	{
		minus = true;
		this->integer = -integer;
	}
#ifdef DEBUG
	cout << "Constructor1:\t" << this << endl;
#endif // DEBUG
}
Fraction::Fraction(double decimal)
{
	decimal += 1e-10;
	minus = false;
	if (decimal < 0)
	{
		minus = true;
		decimal = -decimal;
	}
	integer = decimal;
	decimal -= integer;
	denominator = 1e+9;
	numerator = decimal * denominator;
	reduce();
#ifdef DEBUG
	cout << "Constructor  double:\t" << this << endl;
#endif // DEBUG
}
Fraction::Fraction(int numerator, int denominator)
{
	this->minus = false;
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	if (numerator < 0)
	{
		minus = true;
		this->numerator = -numerator;
	}
	cout << "Constructor2:\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->minus = false;
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	if (integer < 0)
	{
		minus = true;
		this->integer = -integer;
	}
	if (numerator < 0)
	{
		minus = true;
		this->numerator = -numerator;
	}
	cout << "Constructor3:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t" << this << endl;
}
Fraction& Fraction::operator=(const Fraction& other)
{
	this->minus = other.minus;
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	return *this;
}
Fraction& Fraction::operator+=(const Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction::operator-=(const Fraction& other)
{
	return *this = *this - other;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}
//         increment/decrement
Fraction& Fraction::operator++()
{
	this->integer++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	this->integer++;
	return old;
}
//          Type cast operators:
Fraction::operator int() const
{
	return minus ? -integer : integer;
}

Fraction::operator double() const
{
	double number = integer + (double)numerator / denominator;
	if (minus)number = -number;
	return number;
}

//         Methods:
Fraction& Fraction::to_proper()
{
	/*if (integer >= 0)integer += numerator / denominator;
	else integer -= numerator / denominator;*/
	integer += numerator / denominator;
	get_minus_from_number();
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::to_improper()
{
	get_minus_from_number();
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::reduce()
{
	if (numerator == 0)return *this;
	int more, less, rest;
	//Выясняем кто больше, числитель, или знаменатель:
	if (numerator > denominator)more = numerator, less = denominator;
	else less = numerator, more = denominator;
	//Находим наибольший общий делитель:
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;	//Greatest Common Divisor
	//Собственно сокращаем дробь:
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	left.set_minus_to_number();
	right.set_minus_to_number();

	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper().get_minus_from_number();
	return result;
}

Fraction operator-(Fraction left, Fraction right)
{
	/*left.to_proper().set_minus_to_number();
	right.to_proper().set_minus_to_number();
	return Fraction
	(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().get_minus_from_number();*/
	left.to_improper().set_minus_to_number();
	right.to_improper().set_minus_to_number();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	result.to_proper().get_minus_from_number();
	if (left.get_minus() || right.get_minus())result.set_minus(true);
	if (left.get_minus() && right.get_minus())result.set_minus(false);
	return result;
}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper().set_minus_to_number();
	right.to_improper().set_minus_to_number();
	Fraction result
	(
		left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()
	);
	result.to_proper();
	if (left.get_minus() || right.get_minus())result.set_minus(true);
	if (left.get_minus() && right.get_minus())result.set_minus(false);
	return result;
}