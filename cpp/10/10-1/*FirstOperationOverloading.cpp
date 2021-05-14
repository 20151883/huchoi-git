#include <iostream>
using namespace std;
//연산자오버로딩에 대한 개념만 확실하다면 매우 쉽게 이해하고 구현할수 있는게 연산자오버로딩 단원.(이 부분때문에 *인거...)
class Point 
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{  }
	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
	}
	Point operator+(const Point &ref)//operator+ 라는 이름의 함수
	{
		Point pos(xpos+ref.xpos, ypos+ref.ypos);
		return pos;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3=pos1.operator+(pos2);

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}
