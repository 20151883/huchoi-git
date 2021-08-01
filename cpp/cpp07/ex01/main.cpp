#include "iter.hpp"

std::ostream &operator<<(std::ostream &ost, int ptr[])
{
	ost<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3];
	return ost;
}

std::ostream &operator<<(std::ostream &ost, float ptr[])
{
	ost<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3];
	return ost;
}


int main(void)
{
	int arr[] = {1,2,3,4};
	std::cout<<"before: "<<arr<<std::endl;
	iter(arr, 4, testfunc<int>);
	std::cout<<"after: "<<arr<<std::endl;

	char arr2[] = "test";
	std::cout<<"before: "<<arr2<<std::endl;
	iter(arr2, 4, testfunc<char>);
	std::cout<<"after: "<<arr2<<std::endl;

	float arr3[] = {1.1,2.1,3.1,4.1};
	std::cout<<"before: "<<arr3<<std::endl;
	iter(arr3, 4, testfunc<float>);
	std::cout<<"after: "<<arr3<<std::endl;
	return 0;
}
