#include <iostream>
using namespace std;
//RacingCarClassBase.cpp와 비교하면 별 차이가 없어보이지만 나중에 가면 구조체와 클래스는 큰 차이가 있음을 알수있음.
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

struct Car
{
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState()
	{
		cout<<"사용자ID: "<<gamerID<<endl;
		cout<<"계기판: "<<fuelGauge<<"%"<<endl;
		cout<<"스피드: "<<curSpeed<<"km/s"<<endl<<endl;
	}
	void Accel()
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
	void Break()
	{
		if(curSpeed<CAR_CONST::BRK_STEP)
		{
			curSpeed=0;
			return;
		}

		curSpeed-=CAR_CONST::BRK_STEP;
	}
};

int main(void)
{
	Car run99={"run99", 100, 0};
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77={"sped77", 100, 0};
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;
}
