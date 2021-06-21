#ifndef __SHRUBBERYCREATIONFORM__
#define __SHRUBBERYCREATIONFORM__

#include "Form.hpp"
#include "Bureaucrat.hpp"
class Form;
class Bureaucrat;

class ShrubberyCreationForm : public Form
{
	private:
		std::string target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const char *target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &src);
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};

#endif
