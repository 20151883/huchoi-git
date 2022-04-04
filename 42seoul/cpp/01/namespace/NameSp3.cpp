#include <iostream>

namespace BestComImpl
{
	void SimpleFunc(void);
	//void PrettyFunc(void);
}

namespace BestComImpl
{
	void PrettyFunc(void);
}

namespace ProgComImpl
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComImpl::SimpleFunc();
	return 0;
}


void BestComImpl::SimpleFunc(void)//함수 정의문을 이렇게 쓰는건 2번예제에서 이미 배웠고, 이 예제에서는 집합관계에 대한 직관을 배울수있는듯..?
{
	std::cout<<"BestCom에서 만든 함수임."<<std::endl;
	PrettyFunc();					// 동일한 namespace.
	ProgComImpl::SimpleFunc();		// 동알하지않은 namespace.
}

void BestComImpl::PrettyFunc(void)
{
	std::cout<<"So Pretty!!"<<std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
	std::cout<<"ProgCom에서 만든 함수임."<<std::endl;
}
