#include "RobotomyRequestForm.hpp"

static int make_robot(std::string target)
{
	std::cout<<"ssshhhhhhhh maaaake rrrrrrobottttttt....thhhhhheeeee nnnnaaaaameeeee issssssisiss ....."<<target<<std::endl;
	return (rand() % 2);
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	check_boundary(executor);
	int ret = make_robot(this->target);
	if (ret == 1)
		std::cout<<this->target<<"  has been robotomized successfully 50% of the time"<<std::endl;
	else
		std::cout<<this->target<<"  robotomized FAILED!!!!!"<<std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return this->target;
}
RobotomyRequestForm::RobotomyRequestForm():Form("RobotomyRequestForm", 72, 45), target("NoName")
{}

RobotomyRequestForm::RobotomyRequestForm(const char *target) :Form("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src):Form("RobotomyRequestForm", 72, 45), target(src.target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
	this->name = src.getName();
	this->sign_bound = src.getSignGrade();
	this->exec_bound = src.getExecGrade();
	this->sign = src.getSign();

	this->target = src.getTarget();
	return *this;
}

Form *RobotomyRequestForm::clone(std::string _target)
{
	Form *ret = new RobotomyRequestForm(_target.c_str());
	return ret;
}