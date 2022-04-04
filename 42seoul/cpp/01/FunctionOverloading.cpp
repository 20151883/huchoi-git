#include <iostream>

void MyFunc(void)
{
	std::cout<<"MyFunc(void) called"<<std::endl;
}

void MyFunc(char c)
{
	std::cout<<"MyFunc(char c) called"<<std::endl;
}

void MyFunc(int a, int b)
{
	std::cout<<"MyFunc(int a, int b) called"<<std::endl;
}

int main(void)//c언어의 컴파일러가 호출대상을 찾는 방법과 병렬적으로 생각하면서 관찰하자. 이것도 합리적인 개념이라 생각이 들지만, 아직 쓰임새를 잘 모르겠음.
{
	MyFunc();
	MyFunc('A');
	MyFunc(12, 13);
	return 0;
}
