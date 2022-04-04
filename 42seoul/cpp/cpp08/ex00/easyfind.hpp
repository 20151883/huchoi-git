#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
void easyfind(T &src, int target)
{
	typename T::iterator result = std::find(src.begin(), src.end(), target);
	if (result == src.end())
		throw std::exception();
	std::cout <<"target은 "<<target <<"이고 target은 " << std::distance(src.begin(), result) + 1 << " 번째 원소"<< std::endl;
}
