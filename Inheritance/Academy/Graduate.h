#pragma once
#include"Student.h"

class Graduate : public Student
{
	string issue;              //Тема дипломной работы
	unsigned int project_size; // Размер работы
public:
	const string& get_issue()const;
	unsigned int get_project_size()const;
	void set_issue(const string& issue);
	void set_project_size(unsigned int project_size);
	//         Constructor:
	Graduate
	(
		human_take_parameters,
		student_get_parameters,
		const string& issue, unsigned int project_size
	);
	~Graduate();
	void info()const;
};
