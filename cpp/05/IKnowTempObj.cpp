#include <iostream>
using namespace std;
//객체를 return하는 함수설명하다가, 임시객체는 언제까지 존재하는지를 설명하기 위해서 만든 예제임.
class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout<<"create obj: "<<num<<endl;
	}
	~Temporary()
	{
		cout<<"destroy obj: "<<num<<endl;  
	}
	void ShowTempInfo()
	{
		cout<<"My num is "<<num<<endl;
	}
};

int main(void)
{
	Temporary(100);//임시객체를 만드는 방법임.
	cout<<"********** after make!"<<endl<<endl;

	Temporary(200).ShowTempInfo();
	cout<<"********** after make!"<<endl<<endl;

	const Temporary &ref=Temporary(300);
	cout<<"********** end of main!"<<endl<<endl;
	return 0;
}