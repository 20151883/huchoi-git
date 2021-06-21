#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	check_boundary(executor);
	std::cout<<getTarget()<<" has been pardoned by Zafod Beeblebrox"<<std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

PresidentialPardonForm::PresidentialPardonForm(const char *target) : Form("PresidentialPardonForm", 25, 5),target(target)
{}

PresidentialPardonForm::PresidentialPardonForm()
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src): Form("PresidentialPardonForm", 25, 5),target(src.target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
	(void)src.target;
	return *this;
}
