#include <iostream>

template <class T>
void testfunc(T &src)
{
	src++;
}

template <typename T>
void iter (T *arr, int lenth, void (*f)(T&))//여기서 함수도 template으로 주고싶은데 잘 못하겠음.
{
	int idx = 0;
	while (idx < lenth)
	{
		f(arr[idx]);
		idx++;
	}
}
