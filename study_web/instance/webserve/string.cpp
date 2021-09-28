#include <string>
#include <iostream>
#include <map>


int main()
{
	std::map<int , std::string> s;
	s[3];
	std::cout << s[3].max_size() << std::endl;
	return 0;
}