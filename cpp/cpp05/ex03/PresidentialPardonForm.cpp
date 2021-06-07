#include "PresidentialPardonForm.hpp"

int PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getSign() == false)
	{
		std::cout<<"this form is not signed!! SIGN FIRST!!!!!"<<std::endl;
		throw SignSkipxception();
	}
	else if (getExecGrade() < executor.getGrade())
	{
		std::cout<<"executor's grade is lower than need grade "<<std::endl;
		throw GradeTooLowException();
	}
	std::cout<<getTarget()<<" has been pardoned by Zafod Beeblebrox"<<std::endl;
	return 1;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}
