#include "Squad.hpp"

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
	if (arr != NULL)
		delete []arr;
}

Squad::Squad(const Squad &src) :count(src.getCount())//객체핸들러(=켄테이너)에서 가장 중요한 부분
{
	this->arr = new ISpaceMarine*[this->count];
	for (int i=0; i < count; i++)
	{
		this->arr[i] = src.getUnit(i)->clone();
	}
}

const Squad &Squad::operator=(const Squad &src)//객체핸들러(=켄테이너)에서 가장 중요한 부분
{
	int i;
	if (this->arr != NULL)
	{
		i = 0;
		while (i < this->count)
		{
			delete arr[i];
			i++;
		}
		delete []arr;
	}
	this->count = src.getCount();
	this->arr = new ISpaceMarine*[this->count];
	for (i=0; i < count; i++)
	{
		this->arr[i] = src.getUnit(i)->clone();
	}
	return *this;
}

int Squad::getCount() const
{
	return this->count;
}

ISpaceMarine* Squad::getUnit(int idx) const
{
	if (count - 1 < idx || idx < 0)
		return NULL;
	return arr[idx];
}

int Squad::push(ISpaceMarine*src)//객체 핸들러(=컨테이너)에서 가장 중요한 부분
{
	int i;
	if (src == NULL)
		return this->count;
	for (i = 0; i < this->count; i++)//ISpaceMarine객체에서 == 연산자 오버로딩을 통해서 객체끼리 비교하는게 좋긴하겠지만, ISpaceMarine 클래스의 정의상 멤버변수가 없어서 그렇게는 할 수가 없음.
	{
		if (arr[i] == src)
			return this->count;
	}
	(this->count)++;
	ISpaceMarine **new_arr = new ISpaceMarine*[this->count];
	for(i = 0; i < this->count - 1; i++)
		new_arr[i] = arr[i];
	//new_arr[i] = src->clone();//;push()함수의 파라미터를 보면 이렇게 clone하는건 옳지 않은듯.. 그러나 컨테이너의 특성상 이렇게 깊은 복사(값의 복사하는게 맞는듯)(test.cpp의 코드와 결과값 관찰해보기)
	new_arr[i] = src;//서브젝트 메인문과 결과값에서는 이 줄을 사용할것을 요구.... 아마도 이 컨테이너의 저장대상은 (ISpaceMarine*)인가보다.***
	if (this->arr)
		delete []this->arr;
	this->arr = new_arr;
	return this->count;
}
