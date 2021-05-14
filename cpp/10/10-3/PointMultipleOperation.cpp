#include <iostream>
using namespace std;

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
	Point operator*(int times)//연산자오버로딩에서 제일 중요한건 함수의반환형인거같음(함수의기능과 연쇄가능성 모두 고려해야함.)
	{
		Point pos(xpos*times, ypos*times);
		return pos;
	}
};

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy=pos*3;
	cpy.ShowPosition();

	cpy=pos*3*2;
	cpy.ShowPosition();
	return 0;
}