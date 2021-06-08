#include "Array.hpp"

int main(void)
{
	try{
		Array <int>test(10);
		int idx = 0;
		/*while (idx < 10)
		{
			test[idx] = "test";
			idx++;
		}*/
		idx = 0;
		//test[11];
		while (idx < 10)
		{
			std::cout<<test[idx++]<<std::endl;
		}
		Array <int>second;
		second = test;
	}
	catch(...)
	{
		std::cout<<"error"<<std::endl;
	}
	return 0;
}
