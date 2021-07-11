#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

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
		const std::string &getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};
#endif