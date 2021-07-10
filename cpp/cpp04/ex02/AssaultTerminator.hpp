#ifndef __ASSAULTTERMINATOR__
#define __ASSAULTTERMINATOR__

#include "ISpaceMarine.hpp"

class AssaultTerminator :public ISpaceMarine//왜 이 클래스의 부모클래스를 인터페이스 클래스로 두었는지...?
{
	private:

	public:
		AssaultTerminator();
		virtual ~AssaultTerminator();
		AssaultTerminator(const AssaultTerminator &src);
		const AssaultTerminator &operator=(const AssaultTerminator &src);
		virtual ISpaceMarine* clone() const;
		virtual void battleCry() const;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;
};
#endif
