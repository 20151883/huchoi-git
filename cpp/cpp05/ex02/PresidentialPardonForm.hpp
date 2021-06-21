#include "Form.hpp"
#include "Bureaucrat.hpp"
class Form;
class Bureaucrat;

class PresidentialPardonForm : public Form
{
	private:
		std::string target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(const char *target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(PresidentialPardonForm &src);
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};
