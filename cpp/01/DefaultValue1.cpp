#include <iostream>

int Adder(int num1=1, int num2=2)
{
	return num1+num2;
}

int main(void)//되게 합리적인 개념이긴하나, 아직 쓰임새를 잘 모르겠음.
{
	std::cout<<Adder()<<std::endl;
	std::cout<<Adder(5)<<std::endl;
	std::cout<<Adder(3, 5)<<std::endl;
	return 0;
}
