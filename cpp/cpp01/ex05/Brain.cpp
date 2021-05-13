#include "Brain.hpp"

std::string Brain::identify() const
{
    long long num = (long long)this;
    const char *arr = "01234567890ABCDEF";
    std::string ret;
    ret.insert(0, "0x");
    while (num != 0)
    {
		ret.insert(2,1,arr[num % 16]);
		num/=16;
    }
	return ret;
}
