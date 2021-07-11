#include "Form.hpp"

Form::Form(const char *name, int sign_bound, int exec_bound) :name(name), sign_bound(sign_bound), exec_bound(exec_bound), sign(false)
{
	if (sign_bound < 1)
		throw GradeTooHighException();
	if (sign_bound >150)
		throw GradeTooLowException();
	if (exec_bound < 1)
		throw GradeTooHighException();
	if (exec_bound >150)
		throw GradeTooLowException();
}

Form::Form(const Form &src)
{
	*this = src;
}

const Form & Form::operator=(const Form &src)
{
	this->name = src.getName();
	this->sign_bound = src.getSignGrade();
	this->exec_bound = src.getExecGrade();
	this->sign = src.getSign();
	return (*this);
}

Form::~Form()
{

}

const char * Form::GradeTooHighException::what() const noexcept//오버라이딩
{
	return "TOO HIGH  BOUND";
}


const char * Form::GradeTooLowException::what() const noexcept//오버라이딩
{
	return "TOO LOW  BOUND";
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getSign() const
{
	return this->sign;
}

int Form::getSignGrade() const
{
	return this->sign_bound;
}

int Form::getExecGrade() const
{
	return this->exec_bound;
}

void Form::beSigned(Bureaucrat &src)
{
	if (this->sign_bound >= src.getGrade() && this->sign == false)
		this->sign = true;
	else if (this->sign_bound < src.getGrade())
		throw GradeTooLowException();
	else
		throw std::exception();
}

std::ostream& operator<<(std::ostream &ost, const Form &src)
{
	ost << "name: "<<src.getName()<<"  signed? "<<src.getSign()<<"  sign bound: "<<src.getSignGrade()<<"  exec bound: "<<src.getExecGrade();
	ost.flush();
	return ost;
}
