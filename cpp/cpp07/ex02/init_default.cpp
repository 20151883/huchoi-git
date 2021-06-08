#include <iostream>

int main(void)
{
	int *p = new int();
	std::cout<<*p<<std::endl;

	int *arr = new int[3];
	std::cout<<arr[0]<<arr[1]<<arr[2]<<std::endl;
	delete &arr[0];
	delete &arr[1];
	return 0;
}
