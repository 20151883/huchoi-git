#include <iostream>

template <class T>
void swap(T &arg1, T &arg2)
{
	T temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template <class T>
T min(T arg1, T arg2)
{
	if(arg1 == arg2)
		return arg2;
	else if (arg1 > arg2)
		return arg2;
	else
		return arg1;
}

template <class T>
T max(T arg1, T arg2)
{
	if(arg1 == arg2)
		return arg2;
	else if (arg1 > arg2)
		return arg1;
	else
		return arg2;
}
