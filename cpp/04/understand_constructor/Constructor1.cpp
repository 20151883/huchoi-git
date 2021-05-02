#include <iostream>
using namespace std;

class SimpleClass
{
	int num1;
	int num2;

public:
	SimpleClass()//생성자는 객체생성과정에서 자동으로 호출된다.(그래서 이름이 생성자인가보다)
	{
		num1=0;
		num2=0;
	}
	SimpleClass(int n)//기본적으로 생성자도 하나의 함수이다.
	{
		num1=n;
		num2=0;
	}
	SimpleClass(int n1, int n2)
	{
		num1=n1;
		num2=n2;
	}

	/*
	SimpleClass(int n1=0, int n2=0)
	{
		num1=n1;
		num2=n2;
	}
	*/

	void ShowData() const
	{
		cout<<num1<<' '<<num2<<endl;
	}
};

int main(void)
{
	SimpleClass sc1;//SimpleClass sc1() 라고 적으면 문제가 생길게 뻔하니까, 그런 문제상황을 피하기위해서...!
	sc1.ShowData();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();
	return 0;
}
