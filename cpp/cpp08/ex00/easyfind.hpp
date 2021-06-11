#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
template <class T>
void easyfind(T &src, int target)//T = std::vector <int> 타입의 자료형
{
	auto result = std::find(src.begin(), src.end(), 3);
	std::cout << "3 은 " << std::distance(src.begin(), result) + 1 << " 번째 원소"
            << std::endl;
	if (result == src.end())
		throw std::exception();
}
