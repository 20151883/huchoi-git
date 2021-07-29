#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>//iostream에 fstream들어있는줄 알았는데 아니였음.

class ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const char *target);
		 ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		 void execute(Bureaucrat const & executor) const;
		Form		*clone(const char *str);
};

#endif
