#include <iostream>
//함수 디폹므 인자에 대한 기본개념
//함수 정의할떄 오른쪽에서 왼쪽으로 쓰고
//함수 호출할떄는 왼쪽에서 오른쪽으로 전달된다. 
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
