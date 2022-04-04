#include "Serialization.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

std::ostream& operator<<(std::ostream &ost, Data src)
{
    ost<<src.num<<" "<<src.c<<" "<<src.f<<" "<<src.d<<" "<<src.str;
    ost.flush();
    return ost;
}