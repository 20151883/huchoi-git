#include "Brain.hpp"

std::string Brain::identify() const
{
	//std::cout<<this<<std::endl;
    long long address = (long long)this;
    const char *arr = "0123456789ABCDEF";
    std::string ret;
   
    while (address != 0)
    {
		ret.insert(0, 1, arr[address % 16]);
		address/=16;
    }
	 ret.insert(0, "0x");
	return ret;
}

Brain::~Brain()
{
	std::cout<<"brain is dead"<<std::endl;
}
