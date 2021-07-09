#include "ISquad.hpp"

Squad::Squad() :count(0), arr(NULL)
{}

Squad::~Squad()
{
	int i = 0;
	while (i < count)
	{
		delete arr[i];
		i++;
	}
	delete []arr;
}

Squad::Squad(const ISquad &src) :count(src.getCount())//체크할것
{
	this->arr = new ISpaceMarine*[this->count];
	ISpaceMarine *ptr;
	for (int i=0; i < count; i++)
	{
		ptr = src.getUnit(i)->clone();
		this->arr[i] = ptr;
	}
}

Squad &Squad::operator=(const ISquad &src)//체크할것
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

int Squad::getCount() const
{
	return this->count;
}

ISpaceMarine* Squad::getUnit(int idx) const
{
	if (count - 1 < idx)
		return NULL;
	return arr[idx];
}

int Squad::push(ISpaceMarine*src)//체크할것
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
