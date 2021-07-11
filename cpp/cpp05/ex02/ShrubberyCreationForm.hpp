#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>//iostream에 fstream들어있는줄 알았는데 아니였음.

class ShrubberyCreationForm : public Form
{
	private:
		std::string target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const char *target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		const std::string &getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};

#endif
