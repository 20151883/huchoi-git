#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class RobotomyRequestForm : public Form
{
	private:
		std::string target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(const char *target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(RobotomyRequestForm &src);
		Form *clone(std::string target);
		virtual void execute(Bureaucrat const & executor) const;
		const std::string & getTarget() const;
};

#endif
