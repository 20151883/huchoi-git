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

std::ostream &operator<<(std::ostream &ost, Form &src)
{
	ost << "name: "<<src.getName()<<"  signed? "<<src.getSign()<<"  sign bound: "<<src.getSignGrade()<<"  exec bound: "<<src.getExecGrade();
	//fflush(ost);fflush해주는게 필요가 없는듯
	return ost;
}
