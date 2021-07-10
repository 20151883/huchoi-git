#ifndef __ISQUAD__
#define __ISQUAD__

#include <iostream>

class ISquad//Interface class!.. 객체핸들러에 대한 부모클래스로 인터페이스 클래스를 두는게 일반적이겠다.
{
	public:
		virtual ~ISquad() {}
		virtual int getCount() const = 0;
		virtual ISpaceMarine* getUnit(int) const = 0;
		virtual int push(ISpaceMarine*) = 0;
};
#endif
