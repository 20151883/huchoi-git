#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *a = new Bureaucrat("test", 3);
	
	try{
		
		a->increasegrade();
		a->increasegrade();
		a->increasegrade();
		//a->increasegrade();
		std::cout<<"finish "<<a->getName()<<" "<<a->getGrade()<<std::endl;
	}
	catch (std::exception & e)//std::exception
	{
		delete a;
		std::cout<<e.what()<<std::endl;
		return (1);
	}
	delete a;
	return (0);
}
