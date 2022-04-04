#include <iostream>
class A {
	void f();
	void g()
	{
		std::cout<<"void g() is called"<<std::endl;
	}
	public:
		void z(void)
		{
			f();
		}
};
void A::f()
{
	// declare pmf as pointer to A member function,
	// taking no args and returning void
	void (A::*pmf)();
	// set pmf to point to A's member function g
	pmf = &A::g;
	// call the member function pointed to by pmf points on this object
	(this->*pmf)(); // calls A::g on this object
}
// using a typedef to preserve sanity - same as above with typedef
// A_pmf_t is a pointer-to-member-function of class A

typedef void (A::*A_pmf_t)();
//typedef void (A::*(test.c_str()))();
void A::f()
{
	A_pmf_t p = &A::g;
	(this->*p)(); // calls A::g on this object
}

/*int main(void)
{
	A temp;
	temp.z();
	return 0;
}*/
