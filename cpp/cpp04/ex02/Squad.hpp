#ifndef __SQUAD__
#define __SQUAD__
#include "ISquad.hpp"
#include <iostream>
class Squad: public ISquad//사실상 이 squad가 객체 핸들러
{
	private:
		int count;
		ISpaceMarine **arr;
	public:
		Squad() :count(0), arr(NULL)
		{}
		~Squad()
		{
			int i = 0;
			while (i < count)
			{
				delete arr[i];
				i++;
			}
			delete []arr;
		}
		Squad(ISquad &src) :count(src.getCount())//복사생성자인데 이게 맞나...?
		{
			this->arr = new ISpaceMarine*[this->count];
			ISpaceMarine *ptr;
			for (int i=0; i < count; i++)
			{
				ptr = src.getUnit(i)->clone();
				this->arr[i] = ptr;
			}
		}
		Squad &operator=(ISquad &src)
		{
			int i;
			if (this->arr != NULL)
			{
				i = 0;
				while (i < count)
				{
					delete arr[i];
					i++;
				}
				this->count = 0;
				delete []arr;
			}
			this->arr = new ISpaceMarine*[this->count];
			ISpaceMarine *ptr;
			for (i=0; i < count; i++)
			{
				ptr = src.getUnit(i)->clone();
				this->arr[i] = ptr;
			}
			return *this;
		}
		virtual int getCount() const
		{
			return this->count;
		}
		virtual ISpaceMarine* getUnit(int idx) const
		{
			if (count - 1 < idx)
				return NULL;
			return arr[idx];
		}
		virtual int push(ISpaceMarine*src)
		{
			int i;
			if (src == NULL)
				return this->count;
			for (i = 0; i < this->count; i++)
			{
				if (arr[i] == src)
					return this->count;
			}
			(this->count)++;
			ISpaceMarine **new_arr = new ISpaceMarine*[this->count];
			for(i = 0;i < this->count - 1;i++)
				new_arr[i] = arr[i];
			if (this->arr)
				delete []this->arr;
			new_arr[i] = src;
			this->arr = new_arr;
			return this->count;
		}
};
#endif
