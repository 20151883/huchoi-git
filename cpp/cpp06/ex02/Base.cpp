#include "Base.hpp"

Base * generate(void)
{
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
	return ret;
}
int is_reference_A(Base &src)
{
	try{
		A &test = dynamic_cast<A &>(src);
		(void)test;
		return 1;
	}
	catch(std::exception &e)
	{
		return 0;
	}
}

int is_reference_B(Base &src)
{
	try{
		B &test = dynamic_cast<B &>(src);
		(void)test;
		return 1;
	}
	catch(std::exception &e)
	{
		return 0;
	}
}

int is_reference_C(Base &src)
{
	try{
		C &test = dynamic_cast<C &>(src);
		(void)test;
		return 1;
	}
	catch(std::exception &e)
	{
		return 0;
	}
}
/////////////////////////////////////////
int is_pointer_A(Base *src)
{
	A *test = dynamic_cast<A *>(src);
	if (test == NULL)
		return 0;
	return 1;

}

int is_pointer_B(Base *src)
{

	B *test = dynamic_cast<B *>(src);
	if (test == NULL)
		return 0;
	return 1;
}

int is_pointer_C(Base *src)
{

	C *test = dynamic_cast<C *>(src);
	if (test == NULL)
		return 0;
	return 1;
}

void identify_from_pointer(Base * p)
{
	if (is_pointer_A(p))
		std::cout<<"A"<<std::endl;
	if (is_pointer_B(p))
		std::cout<<"B"<<std::endl;
	if (is_pointer_C(p))
		std::cout<<"C"<<std::endl;
}

void identify_from_reference(Base & p)
{
	if (is_reference_A(p))
		std::cout<<"A"<<std::endl;
	if (is_reference_B(p))
		std::cout<<"B"<<std::endl;
	if (is_reference_C(p))
		std::cout<<"C"<<std::endl;
}
