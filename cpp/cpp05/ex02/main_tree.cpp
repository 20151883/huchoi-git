#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
int main(void)
{
	Bureaucrat* mike = new Bureaucrat("mike", 1);
    Bureaucrat* chuck = new Bureaucrat("chuck", 10);
    Bureaucrat* janny = new Bureaucrat("janny", 100);

	ShrubberyCreationForm a = ShrubberyCreationForm("new_tree_file");
	//Bureaucrat b = Bureaucrat()

	mike->signForm(a);
    mike->executeForm(a);
}
