#include "Serialization.hpp"

int main(void)
{
	Data test = {10, 'c', 1.1, 2.2, std::string("test")};
	std::cout<<test<<std::endl;
	uintptr_t uintptr = serialize(&test);
	Data *dataptr = deserialize(uintptr);
	std::cout<<*dataptr<<std::endl;
	std::cout<<sizeof(uintptr_t)<<std::endl;
	return 0;
}
