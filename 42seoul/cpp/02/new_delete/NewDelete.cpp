#include <iostream>
#include <string.h>
using namespace std;

char * MakeStrAdr(int len)
{
	// char * str=(char*)malloc(sizeof(char)*len);
	char * str=new char[len];//우측에 와야하는것: 자료형과 (필요하다면)필요한 개수(...?)
	return str;
}

int main(void)
{
	char * str=MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout<<str<<endl;
	// free(str);
	delete []str;
	return 0;
}
