#include <iostream>
using namespace std;

int main(void)
{
	std::string test = std::string("test string");
	std::string::iterator iter = test.begin();
	for (iter = test.begin() ; iter != test.end() ; iter++)
		std::cout << *iter;
	std::cout << std::endl;
	return 0;
}
