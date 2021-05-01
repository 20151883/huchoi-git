#include <iostream>//intput output stream을 뜻하는듯..

int main(void)//printf와 병렬적으로 생각하면서 관찰해보기
{
	int num=20;
	std::cout<<"Hello World!"<<std::endl;
	std::cout<<"Hello "<<"World!"<<std::endl;
	std::cout<<num<<' '<<'A';
	std::cout<<' '<<3.14<<std::endl;
	return 0;
}
