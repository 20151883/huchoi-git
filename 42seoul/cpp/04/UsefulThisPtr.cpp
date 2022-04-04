#include <iostream>
using namespace std;
//this pointer은 지금이나 나중에나 매우 자주, 유용하게 쓰일거같음.
class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1=num1;
		this->num2=num2;
	}

	/*
	TwoNumber(int num1, int num2)
		: num1(num1), num2(num2)
	{
		// empty
	}
	*/	

	void ShowTwoNumber()
	{
		cout<<this->num1<<endl;
		cout<<this->num2<<endl;
	}
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}
