#include "form.hpp"
#include "Bureaucrat.hpp"
int main(void)
{
	try{
		Bureaucrat *a = new Bureaucrat("test", 3);
		Form *form = new Form("test", -10, 1325);
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
