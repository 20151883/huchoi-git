#ifndef __CARINLINE_H__
#define __CARINLINE_H__

#include <iostream>
using namespace std;
//인라인 함수를 헤더파일에 넣어야만 하는 이유에 대해 서술하시오.
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

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(char * ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

inline void Car::ShowCarState()
{
	cout<<"������ID: "<<gamerID<<endl;
	cout<<"���ᷮ: "<<fuelGauge<<"%"<<endl;
	cout<<"����ӵ�: "<<curSpeed<<"km/s"<<endl<<endl;
}


inline void Car::Break()
{
	if(curSpeed<CAR_CONST::BRK_STEP)
	{
		curSpeed=0;
		return;
	}
	curSpeed-=CAR_CONST::BRK_STEP;
}

#endif
