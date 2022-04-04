#include <iostream>

namespace BestComImpl//namespace에 함수 선언문만을 넣어두고, 함수 정의문은 밖에 두니 가독성이 훨씬좋음.(함수 선언문과 정의문을 분리하는 이유는 가독성을 위함임)
{
	void SimpleFunc(void);
}

namespace ProgComImpl
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}


void BestComImpl::SimpleFunc(void)//함수 선언문과 정의문을 분리할거라면, 함수정의문을 이렇게 만들어야 하는듯...
{
	std::cout<<"BestCom에서 만든 함수임."<<std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
	std::cout<<"ProgCom에서 만든 함수임."<<std::endl;
}
