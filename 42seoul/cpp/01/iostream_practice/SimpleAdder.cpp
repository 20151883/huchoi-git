#include <iostream>

int main(void)//scanf와 병렬적으로 생각하면 관찰해보기
{
	int val1;
	std::cout<<"첫번째 숫자: ";
	std::cin>>val1;

	int val2;
	std::cout<<"두번째 숫자: ";
	std::cin>>val2;

	int result=val1+val2;
	std::cout<<"두 수의 덧셈결과: "<<result<<std::endl;
	return 0;
}
