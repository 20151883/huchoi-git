#include <iostream>
using namespace std;
//복사 생성자에 대해서...
//객체생성시 동일종류의 객체를 인자로 넣어주면, 해당 인자를 받는 생성자(생성자는 함수이다)가 호출될것...
class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2) 
		: num1(n1), num2(n2)//num1=n1, num2=n2와 동일한 의미의 연산임을 이미 배워왔음.
	{
		// empty
	}

	SoSimple(SoSimple &copy)
		: num1(copy.num1), num2(copy.num2)
	{
		cout<<"Called SoSimple(SoSimple &copy)"<<endl;
	}

	void ShowSimpleData()
	{
		cout<<num1<<endl;
		cout<<num2<<endl;
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	cout<<"생성및 초기화 직전"<<endl;
	SoSimple sim2=sim1;
	cout<<"생성및 초기화 직후"<<endl;
	sim2.ShowSimpleData();
	return 0;
}