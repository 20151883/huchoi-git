#include "Serialization.hpp"

void * serialize(void)
{
	std::string str[] = {"geeks", "are", "awesome"};
	int size = str.size();
	std::string ret = "";
	for (int i=0; i<size; i++)
	{
		int ln = str[i].length();
		ret.push_back('0' + ln);
		ret = ret + str[i];
	}
	return ret;
}

Data * deserialize(void * raw)
{
	return NULL;
}
