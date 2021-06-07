#include "form.hpp"

void Form::beSigned(Bureaucrat &src)//관료는 폼에게 사인할것을 요청하고, 그 요청을 받은 폼은 관료에게 사인할것을 요청함.
{
	if (this->sign_bound >= src.getGrade() && this->sign == false)
	{
		this->sign = true;
	}
	/*
	if (src.signForm(*this))
	{
		this->sign = true;//비합리적으로 보이긴하는데.. 문제조건이 이렇게 짜라고 요구를 하니까...
	}*/
}

std::ostream &operator<<(std::ostream &ost, Form &src)
{
	printf("");
	fflush(stdout);
	return ost;
}
