#include "easyfind.hpp"

int main(void)
{
	try{
		std::vector <int> vec;
		vec.push_back(5);
  		vec.push_back(3);
 		vec.push_back(1);
 		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		easyfind(vec, 3);
		easyfind(vec, 4);
		easyfind(vec, 100);
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
		return 1;
	}
	return (0);
}
