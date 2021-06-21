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
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};
