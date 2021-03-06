//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;

#define delimiter "\n----------------------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
	char* str;   //указатель на строку в динамической памяти
	int size;    //размер строки
public:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}
	//             Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << (size == 80? "Default" : "Size") << "Constructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		strcpy(this->str, str); // String copy
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyConstructor: \t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//            Operators:
	String& operator=(const String& other)
	{
		//0) Проверить не является ли другой объект ЭТИМ объектом:
		if (this == &other)return *this;
		delete[] this->str;//1)в первую очередь удаляем старое значение объектаб
		//и только после этого присваиваем ему новое значение.
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyConstructor:\t\t" << this << endl;
		return *this;
	}

	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}

	const char& operator[](int i)const
	{
		return this->str[i];
	}
	char& operator[](int i)
	{
		return this->str[i];
	}

	String operator+=(String& other)
	{
		char* result = new char[this->size + other.size]{};
		this->size += other.size;
		strcpy(result, this->str);
		strcat(result, other.str);
		delete[] this->str;
		this->str = result;
		return *this;
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	//             Methods:
	void print()const
	{
		cout << "str:\t" << str << endl;
		cout << "size:\t" << size << endl;
	}


};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	/*for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];*/
	strcat(result.get_str(), left.get_str());
	strcat(result.get_str(), right.get_str());
	return result;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK
//#define ASIIGNMENT_CHECK


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();

	String str2(5);
	str2.print();

	cout << typeid("Hello").name() << endl;
	String str3 = "Hello";
	str3.print();
	cout << str3 << endl;

	String str4 = str3;
	cout << "str4: - " << str4 << endl;

	String str5;
	str5 = str4;
	cout << "str5: - " << str5 << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ASIIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;


#endif // ASIIGNMENT_CHECK

	String str1 = "Hello";
	String str2 = "World";
	/*cout << delimiter << endl;
	String str3 = str1 + " " + str2;// Оператор + будет выполнять конкатенацию (слияние)строк
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;*/
	cout << delimiter << endl;
	String str3;
	str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;


	/*str1 += str2;
	cout << delimiter << endl;
	cout << str1 << endl;
	cout << delimiter << endl;*/

	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = rand() % 100;
	}
}