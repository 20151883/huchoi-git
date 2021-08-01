#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
	private:
		T *arr;
		unsigned int arr_size;
	public:
		Array();
		Array(unsigned int num);
		Array(Array &src);
		Array &operator=(Array &src);
		T &operator[]( int index);
		const T &operator[]( int index) const;
		unsigned int size() const;
		~Array();
};
#endif