#include "Bureaucrat.hpp"

void	Bureaucrat::signForm(Form &src)
{
	if (src.getSign() == true)
	{
		std::cout<<this->name<<" can not sign "<<src.getName()<<" because the form alraedy signed!!!"<<std::endl;
		return;
	}
	src.beSigned(*this);
	if (src.getSign() == true)
		std::cout<<this->name<<" sign "<<src.getName()<<" sucessfully!!!"<<std::endl;
	else if (this->grade > src.getSignGrade())
		std::cout<<this->name<<" can not sign "<<src.getName()<<" because Bureaucrat's grade is lower than needed grade!!!"<<std::endl;
	/*
	if (this->grade <= src.getSignGrade() && !src.getSign())
	{
		std::cout<<this->name<<" signs "<< src.getName() <<std::endl;
		return 1;
	}
	else if (this->grade > src.getSignGrade() && src.getSign())
		std::cout<<this->name<<" cannot sign "<<src.getName()<<" because "<<"low grade and this form already signed!!!"<<std::endl;
	else if (this->grade > src.getSignGrade())
		std::cout<<this->name<<" cannot sign "<<src.getName()<<" because "<<"low grade"<<std::endl;
	else
		std::cout<<this->name<<" cannot sign "<<src.getName()<<" because "<<"form already signed"<<std::endl;
	return 0;*/
}

std::string Bureaucrat::getName()
{
	return this->name;
}
int Bureaucrat::getGrade()
{
	return this->grade;
}
void Bureaucrat::increasegrade()
{
	this->grade -= 1;
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
}
void Bureaucrat::decreasegrade()
{
	this->grade += 1;
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
}
std::ostream& operator<<(std::ostream &ost, Bureaucrat &src)
{
	printf("<%s>, bureaucrat grade <%d>.", src.getName().c_str(), src.getGrade());
	fflush(stdout);
	return ost;
}
