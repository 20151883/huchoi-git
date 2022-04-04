#include <iostream>
using namespace std;

int main(void)
{
	int num=10;
	int i=0;

	cout<<"true: "<<true<<endl;//이 경우 true: 1 이라는 결과가 나오는데, 그렇다고 bool을 정수형자료형으로 인정하는건아님.
	cout<<"false: "<<false<<endl;

	while(true)
	{
		cout<<i++<<' ';
		if(i>num)
			break;
	}
	cout<<endl;

	cout<<"sizeof 1: "<<sizeof(1)<<endl;
	cout<<"sizeof 0: "<<sizeof(0)<<endl;
	cout<<"sizeof true: "<<sizeof(true)<<endl;
	cout<<"sizeof false: "<<sizeof(false)<<endl;
	return 0;
}