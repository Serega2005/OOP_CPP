#include<iostream>
using namespace std;

//создание структуры:
class Point
{
	//Структура Point описывает точки на плоскости.
	double x;//координаты по x
	double y;//координаты по y
public:
	double get_x()
	{
		return x;
	}
	double get_y()
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
	Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Destructor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//                 Methods:
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}

};
//создавая структуру или класс мы создаём новый тип данных, а объявляя объекты этошо класса или структуры мы создаём переменные нашего типа

//        класс - это тип данных
//    структура - это тоже тип данных
//       объект - это самая обычная переменная 

//#define INTRO
#define CONSTRUCTORS

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

//#ifdef CONSTRUSTORS
	Point A;
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B = 5;
	B.print();
//#endif // CONSTRUSTORS
}