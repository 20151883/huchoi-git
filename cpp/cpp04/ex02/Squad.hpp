#ifndef __SQUAD__
#define __SQUAD__

#include "ISquad.hpp"
#include <iostream>

class Squad: public ISquad//사실상 이 squad가 "객체 핸들러"..
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
