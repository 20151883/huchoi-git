#include "Form.hpp"
void Form::beSigned(Bureaucrat &src)
{
	if (this->sign_bound >= src.getGrade() && this->sign == false)
		this->sign = true;
	else if (this->sign_bound < src.getGrade())
		throw GradeTooLowException();
	else
		throw std::exception();
}
void Form::check_boundary(Bureaucrat const &src) const
{
	if (this->sign == false)
		throw std::exception();
	else if (this->exec_bound < src.getGrade())
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const char *name, int sign_bound, int exec_bound) :name(src.name), sign_bound(src.sign_bound), exec_bound(src.exec_bound), sign(src.sign)
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

Form::Form()
{
}
Form::Form(Form &src):name(src.name), sign_bound(src.sign_bound), exec_bound(src.exec_bound), sign(src.sign)
{
}

Form::~Form()
{

}
std::string Form::getName() const
{
	return this->name;
}
bool Form::getSign()
{
	return this->sign;
}
int Form::getSignGrade()
{
	return this->sign_bound;
}
int Form::getExecGrade()
{
	return this->exec_bound;
}

const char * Form::GradeTooLowException::what() const _NOEXCEPT//오버라이딩
{
	return "TOO LOW";
}

const char * Form::GradeTooHighException::what() const _NOEXCEPT//오버라이딩
{
	return "TOO HIGH";
}

std::ostream &operator<<(std::ostream &ost, Form &src)
{
	ost << "name: "<<src.getName()<<"  signed? "<<src.getSign()<<" sign bound: "<<src.getSignGrade()<<"  exec bound: "<<src.getExecGrade();
	//fflush(ost);fflush해주는게 필요가 없는듯
	return ost;
}
