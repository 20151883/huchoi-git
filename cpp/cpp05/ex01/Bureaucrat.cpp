#include "Bureaucrat.hpp"

int	Bureaucrat::signForm(Form &src)
{
	if (this->range <= src.getSignGrade() && !src.getSign())
	{
		std::cout<<this->name<<" signs "<< src.getName() <<std::endl;
		return 1;
	}
	else if (this->range > src.getSignGrade() && src.getSign())
		std::cout<<this->name<<" cannot sign "<<src.getName()<<" because "<<"low grade and this form already signed!!!"<<std::endl;
	else if (this->range > src.getSignGrade())
		std::cout<<this->name<<" cannot sign "<<src.getName()<<" because "<<"low grade"<<std::endl;
	else
		std::cout<<this->name<<" cannot sign "<<src.getName()<<" because "<<"form already signed"<<std::endl;
	return 0;
}
std::string getName()
{
	return this->name;
}
int getGrade()
{
	return this->range;
}
void increaseRange()
{
	this->range -= 1;
	if (range < 1)	
		throw GradeTooLowException();
	else if (range > 150)
		throw GradeTooHighException();
}
void decreaseRange()
{
	this->range += 1;
	if (range < 1)
		throw GradeTooLowException();
	else if (range > 150)
		throw GradeTooHighException();
}
std::ostream& operator<<(std::ostream &ost, Bureaucrat &src)
{
	printf("<%s>, bureaucrat grade <%d>.", src.getName().c_str(), src.getGrade());
	fflush(stdout);
	return ost;
}
