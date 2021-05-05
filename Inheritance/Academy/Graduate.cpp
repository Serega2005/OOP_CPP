#include"Graduate.h"


const string& Graduate::get_issue()const
{
	return issue;
}
unsigned int Graduate::get_project_size()const
{
	return project_size;
}
void Graduate::set_issue(const string& issue)
{
	this->issue = issue;
}
void Graduate::set_project_size(unsigned int project_size)
{
	this->project_size = project_size;
}
//         Constructor:
Graduate::Graduate
(
	human_take_parameters,
	student_get_parameters,
	const string& issue, unsigned int project_size
) :Student(human_give_parameters, student_give_parameters)
{
	set_issue(issue);
	set_project_size(project_size);
	cout << "GConstructor:\t" << this << endl;
}
Graduate::~Graduate()
{
	cout << "GDestructor:\t" << this << endl;
}
void Graduate::info()const
{
	Student::info();
	cout << "“ема дипломной работы: " << issue << ", размер работы: " << project_size << " страниц" << endl;
}

ostream& operator<<(ostream& os, const Graduate& obj)
{
	return os << (Student)obj << obj.get_issue() << " " << obj.get_project_size();
}
