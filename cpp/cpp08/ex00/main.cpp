#include "easyfind.hpp"

/*template <class Iter>
std::ostream &print(std::ostream &ost, Iter &src)
{

	return ost;
}*/

template <class Iter>
void print(Iter begin, Iter end)
{
	if (begin == end)
		return;
	while (begin != end)
	{
		std::cout<<*begin<<" , ";
		begin++;
	}
	std::cout<<std::endl;
}

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
		print(vec.begin(), vec.end());
		easyfind(vec, 3);
	}
	catch(std::exception &e)
	{
		e.what();
	}
	return (0);
}
