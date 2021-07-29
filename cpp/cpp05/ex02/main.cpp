#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
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

    //////////////////////////////////////////////////////////////////

    /*Bureaucrat* mike = new Bureaucrat("mike", 1);
    Bureaucrat* chuck = new Bureaucrat("chuck", 10);
    Bureaucrat* janny = new Bureaucrat("janny", 100);
	Bureaucrat* huchoi = new Bureaucrat("huchoi", 150);

	ShrubberyCreationForm a = ShrubberyCreationForm("new_tree_file");
	//Bureaucrat b = Bureaucrat()

	mike->signForm(a);
    mike->executeForm(a);
	chuck->signForm(a);
    chuck->executeForm(a);
	janny->signForm(a);
    janny->executeForm(a);
	huchoi->signForm(a);
    huchoi->executeForm(a);*/

    //////////////////////////////////////////////////////////////////

    /*
    //ShrubberyCreationForm* Shrubbery = new ShrubberyCreationForm("Shrubbery");
    // sign 145, exec 137
    //RobotmyRequestForm* robot = new RobotmyRequestForm("Bob");
    // sign 72, exec 45
    PresidentialPardonForm* president = new PresidentialPardonForm("president");
    PresidentialPardonForm* initP = new PresidentialPardonForm("president");
    // sign 25, exec 5

    Bureaucrat* mike = new Bureaucrat("mike", 1);
    Bureaucrat* chuck = new Bureaucrat("chuck", 10);
    Bureaucrat* janny = new Bureaucrat("janny", 100);

    std::cout << std::endl;
    //mike->signForm(*Shrubbery);
    //mike->executeForm(*Shrubbery);

    std::cout << std::endl;
    mike->signForm(*president);
    mike->executeForm(*president);

    std::cout << std::endl;
    *president = *initP;
    chuck->signForm(*president);
    chuck->executeForm(*president);

    std::cout << std::endl;
    *president = *initP;
    janny->signForm(*president);
    janny->executeForm(*president);

    std::cout << std::endl;
    delete president;
    delete initP;
    delete mike;
    delete chuck;
    delete janny;*/

    return (0);
}