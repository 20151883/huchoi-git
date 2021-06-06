#include "form.hpp"

void Form::beSigned(Bureaucrat &src)
{
	Form test = *this;
	if (src.signForm(test))
	{
		this->sign = true;
	}
}

std::ostream &operator<<(std::ostream &ost, Form &src)
{
	printf("");
	fflush(stdout);
	return ost;
}
