#include "Bureaucrat.hpp"

int main(void)
{
	try{
		Bureaucrat *a = new Bureaucrat("test", 3);
		a->increaseRange();
		a->increaseRange();
		a->increaseRange();
		std::cout<<"finish "<<a->getName()<<" "<<a->getGrade()<<std::endl;
	}
	catch (std::exception & e)//std::exception
	{
		std::cout<<e.what()<<std::endl;
	}
}
