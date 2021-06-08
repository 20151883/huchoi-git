#include <iostream>
template <class T>
class Array
{
	private:
		T *arr;
		unsigned int arr_size;
	public:
		Array()//빈 배열을 만들어라..?
		{
			arr = new T[0];
			arr_size = 0;
		}
		Array(unsigned int num)
		{
			arr = new T[num];
			arr_size = num;
			unsigned int idx = 0;
			while (idx < num)
			{
				arr[idx] = T();
				idx++;
			}
		}
		Array(Array &src)//깊은복사하기
		{
			int lenth = src.size();
			this->arr = new T [lenth];
			int idx = 0;
			while (idx < lenth)
			{
				T data = src[idx];
				this->arr[idx] = T(data);
				idx++;
			}
		}
		Array &operator=(Array &src)//깊은복사하기
		{
			int lenth = src.size();
			if (this->arr != NULL)
				delete []this->arr;
			this->arr = new T [lenth];
			int idx = 0;
			while (idx < lenth)
			{
				this->arr[idx] = src[idx];
				idx++;
			}
			return *this;
		}
		T &operator[](int index)//레퍼런스형으로 반환하는게 맞을듯. "[ ]"연산자특성상..
		{
			if (arr_size <= index || index < 0)
				throw std::exception();
			else
				return this->arr[index];
		}
		int size() const
		{
			return (this->arr_size);
		}
		~Array()
		{
			unsigned int idx = 0;
			delete []arr;
			std::cout<<"all allocated member is freed...."<<std::endl;
		}
};
