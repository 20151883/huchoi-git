#include<iostream>
#include <fstream>

using namespace std;

void pyramid(int start, int end, std::ofstream &test)
{
	for(int i=start; i<=end; i++)
	{
		for(int spaces=1; spaces<=end-i; spaces++) test<<" "; //spaces
		for(int j=1; j<=(2*i)-1; j++) test<<"*"; //pyramid
		test<<endl; //newline
	}
}

void base(int rows, std::ofstream &test)
{
	for(int i=0; i<=rows*0.3; i++)
	{
		for(int spaces=1; spaces<=rows*0.75; spaces++) test<<" "; //spaces
		for(int j=1; j<=rows*0.5; j++) test<<"*"; //stars
		test<<endl; //newline
	}
}

int main()
{
	std::ofstream test("test.txt", std::ios::trunc);
	if (test.is_open())
		std::cout<<"open is ok"<<std::endl;
	int rows=15;
	pyramid(0,rows, test);
	pyramid(rows/2,rows, test);
	pyramid(rows/2,rows, test);
	base(rows, test);
}
