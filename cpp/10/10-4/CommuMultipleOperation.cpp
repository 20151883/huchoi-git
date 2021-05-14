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
	Point operator*(int times) 
	{
		Point pos(xpos*times, ypos*times);
		return pos;
	}
	friend Point operator*(int times, Point & ref);
};

Point operator*(int times, Point & ref)//교환법칙문제를 해결하기위해 여러가지 방법이 있을텐데, 이 방법이 제일 나은듯.
{
	return ref*times;
}

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy=3*pos;
	cpy.ShowPosition();

	cpy=2*pos*3;
	cpy.ShowPosition();
	return 0;
}