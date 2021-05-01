#include <iostream>
using namespace std;

bool IsPositive(int num)//char를 정수형자료형으로 인정하지만, bool은 정수형자료형으로 인정하지 않는다. 이점은 명확하게 할것.
{
   if(num<0)
       return false;//대문자로 적으면 안됨. #define 된게 아님.
   else
       return true;//대문자로 적으면 안됨. #define 된게 아님.
}

int main(void)
{
   bool isPos;
   int num;
   cout<<"Input number: ";
   cin>>num;

   isPos=IsPositive(num);
   if(isPos)
       cout<<"Positive number"<<endl;
   else
       cout<<"Negative number"<<endl;

   return 0;
}
