#include "Intern.hpp"
#include "Bureaucrat.hpp"

class Form;
//clang++ main_intern.cpp Intern.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp Bureaucrat.cpp form.cpp
int main(void)
{
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	Bureaucrat *mike = new Bureaucrat("mike", 1);
	mike->signForm(*rrf);
	mike->executeForm(*rrf);
	return 0;
}
