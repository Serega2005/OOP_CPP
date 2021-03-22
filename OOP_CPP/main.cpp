#include<iostream>
using namespace std;

//�������� ���������:
class Point
{
	//��������� Point ��������� ����� �� ���������.
	double x;//���������� �� x
	double y;//���������� �� y
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
//�������� ��������� ��� ����� �� ������ ����� ��� ������, � �������� ������� ����� ������ ��� ��������� �� ������ ���������� ������ ����

//        ����� - ��� ��� ������
//    ��������� - ��� ���� ��� ������
//       ������ - ��� ����� ������� ���������� 

//#define INTRO
#define CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef INTRO
	int a;
	Point A;  //���������� ������� 'A' ��������� 'Point'
	          //���������� ���������� 'A' ���� 'Point'
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A;//������ ��������� �� ������
	cout << pA->get_x() << "\t" << pA->get_y() << endl;
#endif // INTRO

//#ifdef CONSTRUSTORS
	Point A;
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B = 5;
	B.print();
//#endif // CONSTRUSTORS
}