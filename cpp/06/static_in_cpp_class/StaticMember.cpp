#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		cout<<simObjCnt<<"��° SoSimple ��ü"<<endl;
	}
};
int SoSimple::simObjCnt=0;//마치 전역변수 초기화하는거랑 유사..
//static 멤버변수는 절대로 생성자를 통해서 초기화하지 않는다.
//이렇게 이해하는게 좋겠다. "static멤버변수는 클래스가 만들어짐과 동시에 딱한번, 하나만 생성"된다.
//원래 변수는 만들고 직후에 초기화하는게 좋다. 그런데 이걸 클래스 안에서 진행하면 안되고, 클래스 밖에서 진행해야한다.
//(static멤버변수는 객체의 멤버로 존재하는게 아니다.)
//해당 클래스로부터 만들어진 객체들이 이 변수를 공유하게 된다.
class SoComplex
{
private:
	static int cmxObjCnt;
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
int SoComplex::cmxObjCnt=0;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2=cmx1;
	SoComplex();
	return 0;
}