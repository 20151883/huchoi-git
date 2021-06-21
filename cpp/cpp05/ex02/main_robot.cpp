#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
int main(void)
{
	srand(time(NULL));
	Bureaucrat* mike = new Bureaucrat("mike", 1);
	Bureaucrat* chuck = new Bureaucrat("chuck", 10);
	Bureaucrat* janny = new Bureaucrat("janny", 100);
	Bureaucrat* huchoi = new Bureaucrat("huchoi", 150);

	RobotomyRequestForm a("new_robot");
	mike->signForm(a);
	mike->executeForm(a);
	chuck->signForm(a);
	chuck->executeForm(a);
	janny->signForm(a);
	janny->executeForm(a);
	huchoi->signForm(a);
	huchoi->executeForm(a);
}
