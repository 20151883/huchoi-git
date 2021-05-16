#include <iostream>

inline int SQUARE(int x)//매크로함수의 장점은 취하면서 단점인 복잡함은 해결한 결과가 인라인함수라고 할수있음.2
{
	return x*x;
}

int main(void)
{
	std::cout<<SQUARE(5)<<std::endl;
	std::cout<<SQUARE(12)<<std::endl;
	return 0;
}
