#include "Base.hpp"

int main(void)
{
	Base *test = generate();
	identify_from_pointer(test);
	identify_from_reference(*test);
	delete test;
	return (0);
}
