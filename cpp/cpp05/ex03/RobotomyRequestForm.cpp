#include "RobotomyRequestForm.hpp"


static int make_robot(std::string target)
{
	std::cout<<"ssshhhhhhhh maaaake rrrrrrobottttttt....thhhhhheeeee nnnnaaaaameeeee issssssisiss ....."<<target<<std::endl;
	return (rand() % 2);
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	check_boundary(executor);
	int ret = make_robot(getTarget());
	if (ret == 1)
		std::cout<<getTarget()<<"  has been robotomized successfully 50% of the time"<<std::endl;
	else
		std::cout<<getTarget()<<"  robotomized FAILED!!!!!"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm():Form("RobotomyRequestForm", 72, 45, "noName")
{}

RobotomyRequestForm::RobotomyRequestForm(const char *target) :Form("RobotomyRequestForm", 72, 45, target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src):Form("RobotomyRequestForm", 72, 45, src.getTarget())
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
	setName(src.getName());
	setSignGrade(src.getSignGrade());
	setExecGrade(src.getExecGrade());
	setSign(src.getSign());
	setTarget(src.getTarget());
	return *this;
}

Form		*RobotomyRequestForm::clone(const char *str)
{
	Form *ret = new RobotomyRequestForm(str);
	return ret;
}