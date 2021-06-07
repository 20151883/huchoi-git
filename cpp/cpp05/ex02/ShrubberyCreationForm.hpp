#include "form.hpp"
#include "Bureaucrat.hpp"
class Form;
class Bureaucrat;

class ShrubberyCreationForm : public Form
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm(const char *target) :target(target) ,Form("ShrubberyCreationForm", 145, 137)
		{}
		~ShrubberyCreationForm()
		{}
		//ShrubberyCreationForm(ShrubberyCreationForm &src)
		//{}
		//ShrubberyCreationForm &operator=(ShrubberyCreationForm &src)
		//{}
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};
