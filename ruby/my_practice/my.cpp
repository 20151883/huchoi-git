#include <iostream>

class par
{
	private:
		int num;
	public:
		par(void):num(3)
		{}
		void testing(void)
		{
			std::cout<<"test: "<<this<<std::endl;
		}
};

class test :public par
{
	private:
		int t;
	public:
		test(void):t(4)
		{}
		void real(void)
		{
			std::cout<<"second test: "<<this<<std::endl;
		}
};

int main(void)
{
	test t;
	t.testing();
	t.real();
	return (0);
}
