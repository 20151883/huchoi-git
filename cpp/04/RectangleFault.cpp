#include<iostream>
using namespace std;
//객체의 두가지 특징중, '정보은닉'에 대해 설명하기 위해 빌드업 중인 코드.
class Point
{
public:
	int x;   // 100이하의 음이아닌정수
	int y;   // 100이하의 음이아닌정수
};

class Rectangle
{
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo()
	{
		cout<<"좌 상단: "<<'['<<upLeft.x<<", ";
		cout<<upLeft.y<<']'<<endl;
		cout<<"우 하단: "<<'['<<lowRight.x<<", ";
		cout<<lowRight.y<<']'<<endl<<endl;
	}
};

int main(void)
{
	Point pos1={-2, 4};
	Point pos2={5, 9};
	Rectangle rec={pos2, pos1};
	rec.ShowRecInfo();
	return 0;
}
