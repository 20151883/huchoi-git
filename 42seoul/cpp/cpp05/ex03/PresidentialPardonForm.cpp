#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	check_boundary(executor);
	std::cout<<getTarget()<<" has been pardoned by Zafod Beeblebrox"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const char *target) :Form("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(void)  :Form("PresidentialPardonForm", 25, 5, "noName")
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src): Form("PresidentialPardonForm", 25, 5, src.getTarget())
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
	setName(src.getName());
	setSignGrade(src.getSignGrade());
	setExecGrade(src.getExecGrade());
	setSign(src.getSign());
	setTarget(src.getTarget());
	return *this;
}

Form		*PresidentialPardonForm::clone(const char *str)
{
	Form *ret = new PresidentialPardonForm(str);
	return ret;
}