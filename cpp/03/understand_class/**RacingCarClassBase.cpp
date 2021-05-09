#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN		=20,
		MAX_SPD		=200,
		FUEL_STEP	=2,
		ACC_STEP	=10,
		BRK_STEP	=10
	};
}

class Car//'소속'이라는 키워드를 체화한다는 생각을 가지면 좋을거같음.
{//'정의문' <-> '선언문' 에 대한 인식도 가지면 좋을거같음.
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(const char * ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::InitMembers(const char * ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge=fuel;
	curSpeed=0;
};//함수 인자가 존재하면 마지막에 세미콜론을 붙여줘야 하는듯..
void Car::ShowCarState()
{
	cout<<"사용자ID: "<<gamerID<<endl;
	cout<<"계기판: "<<fuelGauge<<"%"<<endl;
	cout<<"스피드: "<<curSpeed<<"km/s"<<endl<<endl;
}
void Car::Accel()
{
	if(fuelGauge<=0)
		return;
	else
		fuelGauge-=CAR_CONST::FUEL_STEP;

	if((curSpeed+CAR_CONST::ACC_STEP)>=CAR_CONST::MAX_SPD)
	{
		curSpeed=CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed+=CAR_CONST::ACC_STEP;
}
void Car::Break()
{
	if(curSpeed<CAR_CONST::BRK_STEP)
	{
		curSpeed=0;
		return;
	}
	curSpeed-=CAR_CONST::BRK_STEP;
}

int main(void)
{
	Car run99;
	run99.InitMembers("run99", 100);

	run99.Accel();//run99::Accel()라고 쓰는건 클래스와 객체와의 구별이 잘 안된다는것.
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();

	run99.Break();
	run99.ShowCarState();
	return 0;
}
