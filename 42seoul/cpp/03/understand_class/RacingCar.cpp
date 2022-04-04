struct Car//함수는 데이터를 처리하기 위한 도구이다. 따라서 변수(=메모리공간의 이름 && 무엇이든 저장할수있는 그릇)와 함께 존재시키는게 맞을것이다.
{//구조체를 사용하는 이유: 비슷한 부류의 데이터들을 한군데에 모아서 관리를 용이하게 하기위함. 또한 여기에 해당 데이터들을 관리하기위한 함수까지 모아 넣으면 더욱 좋을것.
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState()
	{
		cout<<"������ID: "<<gamerID<<endl;
		cout<<"���ᷮ: "<<fuelGauge<<"%"<<endl;
		cout<<"����ӵ�: "<<curSpeed<<"km/s"<<endl<<endl;
	}
	void Accel()
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
//cpp를 설계하면서의 문제의식: 함수정의문을 구조체 안에 넣자니, 가독성이 좋지않는다. 또한 함수정의문을 구조체 밖으로 빼자니 함수이름 충돌문제(이 부분이 생각보다 빈번히 발생한듯...?)가 생긴다.
//'소속'이라는 키워드에 대해 체화하면 좋을거 같음.
//'정의문' <-> '선언문' 에 대한 인식도 가지면 좋을거같음.
//클래스는 '추상적'이다. 일단 같은 부류의 데이터들(멤버변수)을 모음집이며 해당 데이터들을 처리할수있는 함수(멤버함수)들의 모음집이기도 하다. 더불어 객체이기도하다.
//클래스는 객체이기때문에, state와 behavior 을 가진다. 이 behavior 을 통해 다른 객체랑 소통할 수도 있다. 여기서 소통이란 각자의 state를 보여주고, 필요하면 상대방으로 하여금 state를 변경
//하도록 요구함을 의미한다.