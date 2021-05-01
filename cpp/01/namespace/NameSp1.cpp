#include <iostream>

namespace BestComImpl//네임스페이스를 이렇게 정의하면 가독성이 나쁘다. c에서 함수 선언문과 정의문을 분리했던것도 가독성을 위해서 그랬던것...
{
	void SimpleFunc(void)
	{
		std::cout<<"BestCom이 만든 함수입니다."<<std::endl;
	}
}

namespace ProgComImpl
{
	void SimpleFunc(void)
	{
		std::cout<<"ProgCom이 만든 함수입니다."<<std::endl;
	}
}

int main(void)
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}
