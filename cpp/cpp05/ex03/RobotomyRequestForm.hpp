#include "form.hpp"
#include "Bureaucrat.hpp"
class Form;
class Bureaucrat;

class RobotomyRequestForm : public Form
{
	private:
		std::string target;
	public:
		RobotomyRequestForm(const char *target) :target(target) ,Form("RobotomyRequestForm", 72, 45)
		{}
		~RobotomyRequestForm()
		{}
		//RobotomyRequestForm(RobotomyRequestForm &src)
		//{}
		//RobotomyRequestForm &operator=(RobotomyRequestForm &src)
		//{}
		std::string getTarget() const;
		virtual int execute(Bureaucrat const & executor) const;
};
