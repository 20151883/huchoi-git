#include <iostream>
using namespace std;
//C언어에서의 static
//함수내에 선언된 변수에 static: 지역변수와는 달리 함수가 종료되어도 메모리가 소멸되지 않는다.
//전역변수에 선언된 변수에 static: 선언된 파일내에서만 참조를 허용하겠다.
void Counter()
{
	static int cnt;
	cnt++;
	cout<<"Current cnt: "<<cnt<<endl;
}
	
int main(void)
{
	for(int i=0; i<10; i++)
		Counter();
	return 0;
}
