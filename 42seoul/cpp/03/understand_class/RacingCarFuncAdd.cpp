#include <iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define ID_LEN		20
#define MAX_SPD		200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

struct Car
{
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState()
	{
		cout<<"������ID: "<<gamerID<<endl;
		cout<<"���ᷮ: "<<fuelGauge<<"%"<<endl;
		cout<<"����ӵ�: "<<curSpeed<<"km/s"<<endl<<endl;
	}
	void Accel()//이미 구조체에 소속되었기때문에, 범위지정연산자(::)를 사용할 필요가 없음.. ('소속'이라는 키워드가 cpp에서는 중요한듯...!)
	{
		if(fuelGauge<=0)
			return;
		else
			fuelGauge-=FUEL_STEP;

		if(curSpeed+ACC_STEP>=MAX_SPD)
		{
			curSpeed=MAX_SPD;
			return;
		}

		curSpeed+=ACC_STEP;
	}
	void Break()
	{
		if(curSpeed<BRK_STEP)
		{
			curSpeed=0;
			return;
		}

		curSpeed-=BRK_STEP;
	}
};


int main(void)
{
	Car run99={"run99", 100, 0};//선언과 동시에 초기화를 진행
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77={"sped77", 100, 0};//선언과 동시에 초기화를 진행
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;
}
