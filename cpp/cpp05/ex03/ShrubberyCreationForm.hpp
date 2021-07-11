#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

class Form;

#include "Form.hpp"
#include <fstream>

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
		Form *clone(std::string target);
		virtual void execute(Bureaucrat const & executor) const;
		const std::string & getTarget() const;
};

#endif
