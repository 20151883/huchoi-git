#include <iostream>

template <class T>
void testfunc(T &src)
{
	src++;
}

template <typename T, typename Fp>
void iter (T *arr, int lenth, Fp fp)
{
	int idx = 0;
	while (idx < lenth)
	{
		fp(arr[idx]);
		idx++;
	}
}

