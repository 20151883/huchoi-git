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
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
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
	ost << src.getName()<<", bureaucrat grade "<<src.getGrade()<<"\n";
	fflush(stdout);
	return ost;
}

void Bureaucrat::executeForm(Form const & form) const
{
	if (form.getSign() == false)
	{
		std::cout<<this->name<<"  can not executes  "<<form.getName()<<"because sign is skiped"<<std::endl;//throw catch에서 처리하는데 굳이여기서 또 할필요는 없을듯
	}
	form.execute(*this);
	if (form.getSign() == true)
	{
		std::cout<<this->name<<"  executes  "<<form.getName()<<std::endl;
	}
	else
	{
		std::cout<<this->name<<"  can not executes  "<<form.getName()<<"because grade is lower than needed"<<std::endl;
	}
}
