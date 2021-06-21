#include <iostream>

template <class T>
void testfunc(T &src)
{
	src++;
}
template <class T>
void iter (T arr[], int lenth, void (*f)(T&))
{
	int idx = 0;
	while (idx < lenth)
	{
		f(arr[idx]);
		idx++;
	}
}
