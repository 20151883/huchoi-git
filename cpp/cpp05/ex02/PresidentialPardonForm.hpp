#include "form.hpp"
#include "Bureaucrat.hpp"
class Form;
class Bureaucrat;

class PresidentialPardonForm : public Form
{
	private:
		std::string target;
	public:
		PresidentialPardonForm(const char *target) :target(target) ,Form("PresidentialPardonForm", 25, 5)
		{}
		~PresidentialPardonForm()
		{}
		//PresidentialPardonForm(PresidentialPardonForm &src)
		//{}
		//PresidentialPardonForm &operator=(PresidentialPardonForm &src)
		//{}
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};
