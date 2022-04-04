#include <iostream>
using namespace std;
//class에 static 멤버 변수가 왜 필요한지를 말햐주기위한 빌드업.
int simObjCnt=0;
int cmxObjCnt=0;

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout<<simObjCnt<<"��° SoSimple ��ü"<<endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout<<cmxObjCnt<<"��° SoComplex ��ü"<<endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout<<cmxObjCnt<<"��° SoComplex ��ü"<<endl;
	}
};

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2=com1;
	SoComplex();
	return 0;
}