#pragma warning(disable:4326)
#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"

//#define intheritence_check


void main()
{
	setlocale(LC_ALL, "");
#ifdef inheritence_check
	/*Human human("�������", "�������", 18);
	human.info();*/
	Student vasya("�������", "�������", 18, "����������������", "BV011", 4.5);
	vasya.info();
	cout << delimiter << endl;
	Teacher teacher("Einstein", "Albert", 150, "Phisics", 120);
	teacher.info();
	cout << delimiter << endl;
	Graduate Dima(
		"�������", "�������", 18,
		"����������������", "BV011", 4.5,
		"���������������� �� C++", 25);
	Dima.info();
	cout << delimiter << endl;
#endif // inheritence_check


	//1.Generalization:
	Human* group[] =
	{
		new Student("����������", "����", 16, "���", "PD_011", 5),
		new Student("����������", "�����", 32, "���", "PD_011", 5),
		new Student("������", "������", 17, "���", "PD_011", 5),
		new Graduate("������", "������", 15, "���", "PD_011", 5, "������ ������������ ������", 150),
		new Graduate("�������", "�������", 33, "���", "BV_011", 5, "���������� ������������� ������������� ���� ������", 120),
		new Teacher("Einstein", "Albert", 141, "Astrophysics", 110),
		new Teacher("Richter", "Jeffrie", 45, "Windows development", 20)
	};

	cout << sizeof(group) << endl;
	//2.Specialization:
	cout << delimiter << endl;
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->info();
		cout << typeid(*group[i]).name() << endl;
		//cout << *group[i] << ", ";
		/*if(typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]) << endl;*/
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
}