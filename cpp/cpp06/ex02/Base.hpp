#include <iostream>

class Base
{
	private:

	public:
		~Base()
		{
			std::cout<<"base is destroed!!!"<<std::endl;
		}
};

class A:public Base
{};

class B:public Base
{};

class C:public Base
{};

Base * generate(void);
void identify_from_pointer(Base * p);
void identify_from_reference( Base & p);
