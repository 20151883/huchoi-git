#include <iostream>
using namespace std;

class Base{
	protected:
		int num;
	public:
		Base()
		{}
		void one()
		{
			cout<<"this is Base"<<endl;
			cout<<num<<endl;
		}
};

class Derive :public Base
{

	public:
		Derive(int input):Base()
		{
			num = input;
		}
		void two()
		{
			cout<<"this is derive"<<endl;
			cout<<num<<endl;
		}
};

int main(void)
{
	Derive test(100);
	test.one();
	test.two();
	return (0);
}
