#include <iostream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;

#define delimiter "\n----------------------------------------------------\n"

class Binary
{
	int size;
	int number;
public:
	int get_number()
	{
		return number;
	}
	int get_size()const
	{
		return size;
	}
	void set_number(int number)
	{
		this->number = number;
	}

	//           Constructors:

	Binary()
	{
		this->size = size;
		this->number = number;
		cout << "Constructor0:" << this << endl;
	}
	explicit Binary(int number)
	{
		this->number = number;
	}



};