#include <iostream>

int main(void)
{
	int val1, val2;
	int result=0;
	std::cout<<"두개의 숫자를 'white space로 파싱가능한 형태'로 입력: ";
	std::cin>>val1>>val2;//파싱 가능하게 사용자가 입력을 주어야함.

	if(val1<val2)
	{
		for(int i=val1+1; i<val2; i++)
			result+=i;
	}
	else
	{
		for(int i=val2+1; i<val1; i++)
			result+=i;
	}

	std::cout<<"두 숫자사이의 모든 정수들의 합: "<<result<<std::endl;
	return 0;
}
