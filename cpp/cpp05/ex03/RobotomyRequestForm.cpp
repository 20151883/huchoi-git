#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
static int make_robot(std::string target)
{
	std::cout<<"ssshhhhhhhh maaaake rrrrrrobottttttt....thhhhhheeeee nnnnaaaaameeeee issssssisiss ....."<<target<<std::endl;
	srand(time(NULL));
	rand();
	return (rand() % 2);
}
int RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getSign() == false)
	{
		std::cout<<"this form is not signed!! SIGN FIRST!!!!!"<<std::endl;
		throw SignSkipxception();
	}
	else if (getExecGrade() < executor.getGrade())
	{
		std::cout<<"executor's grade is lower than need grade "<<std::endl;
		throw GradeTooLowException();
	}
	//make_tree(this->target);
	int ret = make_robot(this->target);
	if (ret == 1)
	{
		std::cout<<this->target<<"  has been robotomized successfully 50% of the time"<<std::endl;
		return 1;
	}
	else
	{
		std::cout<<this->target<<"  robotomized FAILED!!!!!"<<std::endl;
		return 0;
	}
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}
