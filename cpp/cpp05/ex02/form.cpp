#include "form.hpp"

void Form::beSigned(Bureaucrat &src)
{
	if (this->sign_bound >= src.getGrade() && this->sign == false)
	{
		this->sign = true;
	}
}

std::ostream &operator<<(std::ostream &ost, Form &src)
{
	ost << "name: "<<src.getName()<<"  signed? "<<src.getSign()<<"  sign bound: "<<src.getSignGrade()<<"  exec bound: "<<src.getExecGrade();
	//fflush(ost);fflush해주는게 필요가 없는듯
	return ost;
}

std::string Form::getName() const
{
	return this->name;
}
bool Form::getSign() const
{
	return this->sign;
}
void Form::setSign(int num = 1)
{
	this->sign = num;
}
int Form::getSignGrade() const
{
	return this->sign_bound;
}
int Form::getExecGrade() const
{
	return this->exec_bound;
}
