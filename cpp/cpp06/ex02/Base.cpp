#include "Base.hpp"
#include <ctime>
Base * generate(void)
{
	srand(time(NULL));
	Base *ret;
	if (rand() / 3 == 0)
	{
		ret = new A();
	}
	else if (rand() / 3 == 0)
	{
		ret = new B();
	}
	else
	{
		ret = new C();
	}
}
int is_A(Base &src)
{
	try{
		Base *test = new Base();
		Base &t = *test;
		dynamic_cast<A&>(t);
		return 1;
	}
	catch(std::exception &e)
	{

	}
}

int is_B()
{
	try{
		Base *test = new Base();
		dynamic_cast<B&>(*test);
		return 1;
	}
	catch(std::exception &e)
	{

	}
}

int is_C()
{
	try{
		Base *test = new Base();
		dynamic_cast<C&>(*test);
		return 1;
	}
	catch(std::exception &e)
	{

	}
}

void identify_from_pointer(Base * p)
{
	B &test = *p;
	if (is_A(test))
		std::cout<<"A"<<std::endl;
	if (is_B(test))
		std::cout<<"B"<<std::endl;
	if (is_C(test))
		std::cout<<"C"<<std::endl;
}

