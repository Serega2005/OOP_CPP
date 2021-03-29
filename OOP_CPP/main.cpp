#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//class Fraction
//{
//	int x;
//	int y;
//public:
//	int get_x()const
//	{
//		return x;
//	}
//	int get_y()const
//	{
//		return y;
//	}
//	void set_x(int x)
//	{
//		this->x = x;
//	}
//	void set_y(int y)
//	{
//		this->y = y;
//	}
//
//	//            Constructor
//
//	Fraction(int x = 0, int y = 0)
//	{
//		//Этот конструктор с параметрами может быть вызван без параметров, с одним параметром, с 2 параметрами
//		this->x = x;
//		this->y = y;
//		cout << "Constructor:\t\t" << this->x << "/" << this->y << endl;
//	}
//	Fraction(const Fraction& other)
//	{
//		//other- это другой объект, копию которого мы создаём
//		this->x = other.x;
//		this->y = other.y;
//		cout << "CopyConstructor:\t" << this->x << "/" << this->y << endl;
//	}
//	~Fraction()
//	{
//		cout << "Destructor:\t\t" << this->x << "/" << this->y << endl;
//	}
//	//               Operators:
//
//	//                 Metods:
//	void fraction()
//	{
//		cout << "X" << x << "/" << "Y" << y << endl;
//	}
//
//	void to_improper(const Fraction& other)const
//	{
//		int x_to_improper = this->x;
//		int y_to_improper = this->y;
//		if (x > y)
//		{
//
//		}
//
//	}
//};

//создание структуры:
class Point
{
	//Структура Point описывает точки на плоскости.
	double x;//координаты по x
	double y;//координаты по y
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//           Constructors;
	//Point()
	//{
	//	//Конструктор по умолчанию создаёт точку в начале координат
	//	x = y = int();//Якобы вызываем конструктор по умолчанию для 'int', и он возвращает значение по умолчанию
	//	cout << "DefautConstructor:\t" << this << endl;
	//}
	//Point(double x)
	//{
	//	//Конструктор с одним параметром создаёт точку на прямой.
	//	this->x = x;
	//	this->y = 0;
	//	cout << "SingleArgumentDestructor:" << this << endl;
	//}
	//Point(double x, double y)
	//{
	//	//Конструктор с параметрами создаёт точку на плоскости
	//	this->x = x;
	//	this->y = y;
	//	cout << "Constructor:\t\t" << this << endl;
	//}
	Point(double x = 0, double y = 0)
	{
		//Этот конструктор с параметрами может быть вызван без параметров, с одним параметром, с 2 параметрами
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		//other- это другой объект, копию которого мы создаём
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//             Operators:
	Point& operator =(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "Operator+=\t\t" << this << endl;
		return *this;
	}

	//        Increment/Decrement

	Point& operator++()//Prefix increment
	{
		this->x++;
		this->y++;
		cout << "Prefix increment+:\t\t" << this << endl;
		return *this;
	}
	Point operator++(int)//Postfix increment
	{
		Point old = *this; //CopyConstructor
		this->x++;
		this->y++;
		cout << "Postfix increment:\t" << this << endl;
		return old;
	}
	/*Point operator+(const Point& other)const
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "operator+" << endl;
		return result;
	}*/
	/*Point operator-(const Point& other)const
	{
		Point result(this->x -other.x, this->y -other.y);
		cout << "operator-" << endl;
		return result;
	}*/
	/*Point operator*(const Point& other)
	{
		return Point(this->x * other.x, this->y * other.y);
	}

	Point operator/(const Point& other)
	{
		return Point(this->x / other.x, this->y / other.y);
	}*/

	//                 Methods:
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
	double distance(const Point& other)const
	{
		//double x_distance = other.x - this->x;
		//double y_distance = other.y - this->y;
		//double distance = sqrt(x_distance * x_distance + y_distance * y_distance);//sqrt -квадратный корень
		//return distance;
		double distance = sqrt((other.x - this->x) * (other.x - this->x) + (other.y - this->y) * (other.y - this->y)); return distance;
	}

};
//создавая структуру или класс мы создаём новый тип данных, а объявляя объекты этошо класса или структуры мы создаём переменные нашего типа

//        класс - это тип данных
//    структура - это тоже тип данных
//       объект - это самая обычная переменная 

double distance(const Point& A, const Point& B)
{
	//double x_distance = A.get_x() - B.get_x();
	//double y_distance = A.get_y() - B.get_y();
	//double distance = sqrt(x_distance * x_distance + y_distance * y_distance);//sqrt -квадратный корень
	//return distance;
	double distance = sqrt((A.get_x() - B.get_x()) * (A.get_x() - B.get_x()) + (A.get_y() - B.get_y()) * (A.get_y() - B.get_y())); return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global plus" << endl;
	return result;
}
Point operator-(const Point& left, const Point& right)
{
	Point result(
		left.get_x() - right.get_x(), 
		left.get_y() - right.get_y()
	);
	cout << "Global minus" << endl;
	return result;
}
Point operator*(const Point& left, const Point& right)
{
	return Point(left.get_x() * right.get_x(), left.get_y() * right.get_y());
}
Point operator/(const Point& left, const Point& right)
{
	return Point(left.get_x() / right.get_x(), left.get_y() / right.get_y());
}

ostream& operator<<(ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << tab << "Y = " << obj.get_y();
}

//#define INTRO
//#define CONSTRUCTORS
//#define DISTANCE
//#define ASSIGNMENT_CHECK
//#define OPERATOR_EXAMPELES
#define OPERATOR_OVERLOADS
//#define ARITHMETICAL_OPERATOR
#define COMPOUNT_ASSIGMENTS

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef INTRO
	int a;
	Point A;  //Объявление объекта 'A' структуры 'Point'
	          //Объявление переменной 'A' типа 'Point'
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A;//Создаём указатель на объект
	cout << pA->get_x() << "\t" << pA->get_y() << endl;
#endif // INTRO

#ifdef CONSTRUSTORS
	Point A;//Defaut Constructor
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B = 5;//Single-Argument constructor
	B.print();

	Point C(8);//Single-Argument constructor
	C.print();

	Point D{ 12 };//Single-Argument constructor
	D.print();

	int a(2);
	int b{ 3 };
	cout << a << tab << b << endl;

	Point E(5, 3);//Parametrized constructor
	E.print();

	Point F = E; //CopyConstructor. Здесь мы создём объект, и инициализируем его другим объектом
	Point G;     //DefaultConstructor
	G = D;       //CopyAssignment - operator=
	G.print();
#endif // CONSTRUSTORS

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	Point A, B, C;
	A = B = C = Point();

#endif // ASSIGNMENT_CHECK

#ifdef DISTANCE
	Point A(2, 3);
	Point B(4, 5);
	A.print();
	B.print();
	cout << A.distance(B) << endl;
	cout << distance(A, B) << endl;
#endif // DISTANCE

#ifdef OPERATOR_EXAMPLES
	cout << A + B << endl; //неявный вызов
	cout << A.operator+(B) << endl;//явный вызов в классе
	cout << operator+(A, B) << endl;//явный вызов за классом
#endif // OPERATOR_EXAMPLES

#ifdef OPERATOR_OVERLOADS

	int a = 2;
	int b = 3;
	int c = a + b;
	a += b;

#ifdef ARITHMETICAL_OPERATOR


	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();
	Point D = A - B;
	D.print();
	//Point F = A.operator*(B);//Явный вызов глобального оператора.
	Point F = operator*(A, B);//Явный вызов глобального оператора.
	F.print();
	(A / B).print();
#endif // ARITHMETICAL_OPERATOR

#ifdef COMPOUNT_ASSIGMENTS
	Point A(2, 3);
	Point B(4, 5);
	A += B;
	A.print();
	/*++A;
	A.print();
	A++;
	A.print();*/
	cout << A++ << endl;
	cout << A << endl;
	cout << ++A << endl;
	cout << A << endl;
#endif // COMPOUNT_ASSIGMENTS

#endif // OPERATOR_OVERLOADS
}