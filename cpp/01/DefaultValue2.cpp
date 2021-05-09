#include <iostream>

int Adder(int num1=1, int num2=2);//함수에 디폴트인자를 넣고싶으면, 이렇게 선언문이랑 정의문이랑 다르게 적는게 일반적인가보다..

int main(void)
{
	std::cout<<Adder()<<std::endl;
	std::cout<<Adder(5)<<std::endl;
	std::cout<<Adder(3, 5)<<std::endl;
	return 0;
}

int Adder(int num1, int num2)
{
	return num1+num2;
}
