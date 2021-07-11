#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	check_boundary(executor);
	std::cout<<getTarget()<<" has been pardoned by Zafod Beeblebrox"<<std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return this->target;
}

PresidentialPardonForm::PresidentialPardonForm(const char *target) :Form("PresidentialPardonForm", 25, 5),target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(void)  :Form("PresidentialPardonForm", 25, 5),target("noName")
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src): Form("PresidentialPardonForm", 25, 5),target(src.getTarget())
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
	this->name = src.getName();
	this->sign_bound = src.getSignGrade();
	this->exec_bound = src.getExecGrade();
	this->sign = src.getSign();

	this->target = src.getTarget();
	return *this;
}

Form *PresidentialPardonForm::clone(std::string _target)
{
	Form *ret = new PresidentialPardonForm(_target.c_str());
	return ret;
}