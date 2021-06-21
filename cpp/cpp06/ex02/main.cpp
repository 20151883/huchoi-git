#include "Base.hpp"
#include "ctime"

int main(void)
{
	srand(time(NULL));
	Base *test = generate();
	identify_from_pointer(test);
	identify_from_reference(*test);
	delete test;
	return (0);
}
