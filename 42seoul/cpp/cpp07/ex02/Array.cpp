#include "Array.hpp"

template <class T>
Array<T>::Array()
{
	arr = NULL;
	arr = new T[0];//이렇게 해도 delete []arr 하면 컴파일 잘 되고 실행해도 에러없이 잘 돌아감.
	arr_size = 0;
}

template <class T>
Array<T>::Array(unsigned int num)
{
	arr = new T[num];
	arr_size = num;
}

template <class T>
Array<T>::Array(Array &src)//깊은복사하기
{
	unsigned int lenth = src.size();
	arr_size = lenth;
	this->arr = new T [arr_size];
	unsigned int idx = 0;
	while (idx < lenth)
	{
		this->arr[idx] = src[idx];
		idx++;
	}
}

template <class T>
Array<T> &Array<T>::operator=(Array<T> &src)
{
	unsigned int lenth = src.size();
	this->arr_size = lenth;
	if (this->arr != NULL)
		delete []this->arr;
	this->arr = new T [lenth];
	unsigned int idx = 0;
	while (idx < lenth)
	{
		this->arr[idx] = src[idx];
		idx++;
	}
	return *this;
}

template <class T>
T &Array<T>::operator[]( int index)
{
	if (arr_size <= (unsigned int)index || index < 0)
		throw std::exception();
	else
		return this->arr[index];
}

template <class T>
const T &Array<T>::operator[]( int index) const
{
	if (arr_size <= (unsigned int)index || index < 0)
		throw std::exception();
	else
		return this->arr[index];
}

template <class T>
unsigned int Array<T>::size() const
{
	return (this->arr_size);
}

template <class T>
Array<T>::~Array()
{
	if (this->arr != NULL)
		delete []arr;
	std::cout<<"all allocated member is freed...."<<std::endl;
}
