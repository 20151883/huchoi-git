#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const char *name, int grade) :name(name)
{
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	else
		this->grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat &src)
{
	(void)src;
}
Bureaucrat::~Bureaucrat()
{

}
Bureaucrat &Bureaucrat::operator=(Bureaucrat &src)
{
	this->name = src.getName();
	this->grade = src.getGrade();
	return *this;
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
	if (grade <= 1)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade -= 1;
}
void Bureaucrat::decreasegrade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade += 1;
}

void Bureaucrat::signForm(Form &src)
{
	try{
		src.beSigned(*this);
		std::cout<<this->name<<" sign the form "<<src.getName()<<std::endl;
	}
	catch(GradeTooHighException &e)
	{
		std::cout<<this->name<<" cannot sign "<<src.getName()<<" because TOO LOW grade"<<std::endl;
	}
	catch(std::exception &e)
	{
		std::cout<<this->name<<" cannot sign "<<src.getName()<<" because it's already signed"<<std::endl;
	}
}
const char * Bureaucrat::GradeTooLowException::what() const _NOEXCEPT//오버라이딩
{
	return "TOO LOW";
}

const char * Bureaucrat::GradeTooHighException::what() const _NOEXCEPT//오버라이딩
{
	return "TOO HIGH";
}

std::ostream& operator<<(std::ostream &ost, Bureaucrat &src)
{
	printf("<%s>, bureaucrat grade <%d>.", src.getName().c_str(), src.getGrade());
	fflush(stdout);
	return ost;
}
