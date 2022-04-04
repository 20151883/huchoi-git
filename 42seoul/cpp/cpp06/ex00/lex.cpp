#include <iostream>
#include <string>
//#include <boost/lexical_cast.hpp>

int main()
{
	std::string i = "12.3456";
	std::string d = "12.3456";

	std::cout << boost::lexical_cast<int>(i) << std::endl;
	std::cout << boost::lexical_cast<double>(d) << std::endl;

	return 0;
}
