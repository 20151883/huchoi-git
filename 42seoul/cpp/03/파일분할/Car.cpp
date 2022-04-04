#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;
//cpp 시작한 시점에서 파일분할에 대한 좋은 습관을 들이라는 의도로 이러한 파일분할을 예제를 들어 보여준듯.
void Car::InitMembers(char * ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge=fuel;
	curSpeed=0;
};

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
