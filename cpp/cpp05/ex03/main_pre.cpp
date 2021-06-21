
#include "PresidentialPardonForm.hpp"
//#include "ShrubberyCreationForm.hpp"

/*static void testForm(Bureaucrat* bur, Form* form)
{
    std::cout << std::endl << "Sign & Execute \033[33m" << form->getName() << "\033[0m : " << std::endl;
    bur->signForm(*form);
    bur->executeForm(*form);
}*/

int main()
{
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
    delete janny;
    return (0);
}
