#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat man_100("man100", 100);
	Bureaucrat man_150("man150", 150);
	Bureaucrat man_50("man50", 50);
	
	Form form_100("form100", 100, 1);
	Form form_150("form150", 150, 1);
	Form form_50("form50", 50, 1);

	man_100.signForm(form_100);
	man_100.signForm(form_150);
	man_100.signForm(form_50);

	man_150.signForm(form_100);
	man_150.signForm(form_150);
	man_150.signForm(form_50);

	man_50.signForm(form_100);
	man_50.signForm(form_150);
	man_50.signForm(form_50);
	return (0);
}
