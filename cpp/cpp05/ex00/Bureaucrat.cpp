#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const char *name, int grade) :name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	this->grade = src.getGrade();
}

Bureaucrat::~Bureaucrat()
{}

const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) 
{
	this->grade = src.getGrade();
	return *this;
}

const std::string &Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::increasegrade()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade -= 1;
}

void Bureaucrat::decreasegrade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade += 1;
}

const char * Bureaucrat::GradeTooLowException::what() const _NOEXCEPT //오버라이딩
{
	return "TOO LOW";
}

const char * Bureaucrat::GradeTooHighException::what() const _NOEXCEPT //오버라이딩
{
	return "TOO HIGH";
}

std::ostream& operator<<(std::ostream &ost, Bureaucrat &src)
{
	ost<<"<"<<src.getName()<<">, bureaucrat grade <"<<src.getGrade()<<">.\n";
	ost.flush();//바로 윗줄에서 개행을 넣어주었는데, 여기서 flush를 해줄 필요가 있는지
	return ost;
}
