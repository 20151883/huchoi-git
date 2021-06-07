#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
int main(void)
{
	Bureaucrat* mike = new Bureaucrat("mike", 1);
    Bureaucrat* chuck = new Bureaucrat("chuck", 10);
    Bureaucrat* janny = new Bureaucrat("janny", 100);

	RobotomyRequestForm a = RobotomyRequestForm("the_new_robot");
	//Bureaucrat b = Bureaucrat()

	mike->signForm(a);
    mike->executeForm(a);
}
