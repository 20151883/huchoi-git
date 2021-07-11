#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

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
		const std::string &getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};

#endif