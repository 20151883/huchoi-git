#include <iostream>
using namespace std;

class SoSimple
{
public:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt=0;

int main(void)
{
	cout<<SoSimple::simObjCnt<<"��° SoSimple ��ü"<<endl;
	SoSimple sim1;
	SoSimple sim2;

	cout<<SoSimple::simObjCnt<<"��° SoSimple ��ü"<<endl;
	cout<<sim1.simObjCnt<<"��° SoSimple ��ü"<<endl;
	cout<<sim2.simObjCnt<<"��° SoSimple ��ü"<<endl;
	//위와같은 크게보면 두가지 방법으로 static멤버변수에 접근할수있다. 하지만 오해를 불러일으키지 않기 위해선 맨위의 방법이 제일 좋다. 
	return 0;
}