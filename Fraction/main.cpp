#include"Fraction.h"

ostream& operator <<(ostream& os, const Fraction& obj)
{
	if (obj.get_minus())os << "(-";
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_integer() && obj.get_numerator())os << "(";
	if (obj.get_numerator())os << obj.get_numerator() << "/" << obj.get_denominator();
	if (obj.get_integer() && obj.get_numerator())os << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	if (obj.get_minus())os << ")";
	return os;
}

bool operator ==(Fraction left, Fraction right)
{
	left.to_improper().reduce();
	right.to_improper().reduce();
	/*if (left.get_numerator() == right.get_numerator() && left.get_denominator() == right.get_denominator())
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return left.get_numerator() == right.get_numerator() && left.get_denominator() == right.get_denominator();
}
bool operator !=(const Fraction& left, const Fraction& right)
{

	return !(left == right);

}
bool operator >(const Fraction& left, const Fraction& right)
{
	/*left.to_improper().reduce();
	right.to_improper().reduce();
	return left.get_numerator() > right.get_numerator() && left.get_denominator() > right.get_denominator();*/
	return (double)left > (double)right;
}
bool operator <(const Fraction& left, const Fraction& right)
{
	/*left.to_improper().reduce();
	right.to_improper().reduce();
	return left.get_numerator() < right.get_numerator() && left.get_denominator()< right.get_denominator();*/
	return (double)left < (double)right;
}
bool operator <=(const Fraction& left, const Fraction& right)
{/*
	left.to_improper().reduce();
	right.to_improper().reduce();
	return left.get_numerator() <= right.get_numerator() && left.get_denominator() <= right.get_denominator();*/
	return left > right || left == right;
}
bool operator >=(const Fraction& left, const Fraction& right)
{
	/*left.to_improper().reduce();
	right.to_improper().reduce();
	return left.get_numerator() >= right.get_numerator() && left.get_denominator() >= right.get_denominator();*/
	return !(left > right);
}
//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define COMPAUND_ASSIGMENTS_CHECK
//#define INCREMENTS_CHECK
#define COMPARISON_OPERATORS

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;      // Default constructor
	cout << A << endl;
	Fraction B = -5;  // Single-Argumet constructor
	cout << B << endl;
	Fraction C(-1, 2);
	cout << C << endl;
	Fraction D(-2, 3, 4);
	cout << D << endl;
#endif // CONSTRUCTORS_CHECK

	/*Fraction A(7, 2);
	cout << A << " = ";
	cout << A.to_proper() << endl;
	cout << A << " = ";
	cout << A.to_improper() << endl;*/

	/*double a = 2.7;
	double b = 3.5;
	cout << a * b << endl;*/

	/*Fraction A(2, 3, 4);
	Fraction B(5, 6, 7);
	cout << A << endl;
	cout << B << endl;*/

#ifdef OPERATORS_CHECK
	cout << A << tab << B << endl;
	cout << A << " + " << B << " = " << A + B << endl;
	cout << B << " - " << B << " = " << B - B << endl;
	cout << B << " - " << A << " = " << B - A << endl;
	cout << A << " - " << B << " = " << A - B << endl;
	cout << A << " * " << B << " = " << A * B << endl;
	cout << A << " / " << B << " = " << A / B << endl;
	cout << A << tab << B << endl;
#endif // OPERATORS_CHECK

#ifdef COMPAUND_ASSIGMENTS_CHECK
	A += B;
	cout << A << endl;
	A -= B;
	cout << A << endl;
	A *= B;
	cout << A << endl;
	A /= B;
	cout << A << endl;
#endif // COMPAUND_ASSIGMENTS_CHECK

#ifdef INCREMENTS_CHECK
	/*Fraction reduse(840, 3600);
	cout << reduse.reduce() << endl;
	cout << Fraction(30, 7).reduce() << endl;
	for (double i = .3; i < 10; i++)
		cout << i << tab;
	cout << endl;
	for (Fraction i(1, 2); i.get_integer() < 10; ++i)
		cout << i << tab;
	cout << endl;
	cout << typeid(3 + 2.5).name() << endl;*/

	//Fraction A = (Fraction)5;   // From int to Fraction
	Fraction A(5); //Если конструктор explicit то его можно вызвать только так.
	cout << "Fraction A = " << A << endl;
	/*cout << sizeof(int) << endl;
	cout << sizeof(Fraction) << endl;*/
	int a = (int)A;
	cout << "int a = " << a << endl;
#endif // INCREMENTS_CHECK


	/*Fraction B(-3, 4, 5);
	cout << B << endl;
	double b = (double)B;
	cout << b << endl;
	int c = (int)B;
	cout << c << endl;
	Fraction C = 2.3;
	cout << C << endl;
	cout << (double)C << endl;*/


#ifdef COMPARISON_OPERATORS
	Fraction F(1, 2);
	Fraction G(5, 11);
	/*if (F == G)
	{
		cout << "Fraction equal" << endl;
	}
	else
	{
		cout << "Fractions different" << endl;
	}*/
	//cout << "Fractions " << (F == G ? "equal" : "different") << endl;

	cout << (F == G) << endl;
	cout << (F != G) << endl;
	cout << (F > G) << endl;
	cout << (F < G) << endl;
	cout << (F >= G) << endl;
	cout << (F <= G) << endl;
#endif // COMPARISON_OPERATORS

	/*
	---------------------------
	operator type()
	{
	   ....
	   ....
	}
	---------------------------
	*/
}