#ifndef __SQUAD__
#define __SQUAD__

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <iostream>

class Squad: public ISquad//사실상 이 squad가 "객체 핸들러".. 객체핸들러는 컨테이너와 같다고 볼수있음. 컨테이너의 핵심에 대해 공부한다고 생각하면 될듯
{
	private:
		int count;
		ISpaceMarine **arr;
	public:
		Squad();
		virtual ~Squad();
		Squad(const Squad &src);
		const Squad &operator=(const Squad &src);
		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int idx) const;
		virtual int push(ISpaceMarine*src);
};

#endif
