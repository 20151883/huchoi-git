#ifndef __ASSAULTTERMINATOR__
#define __ASSAULTTERMINATOR__

#include "ISpaceMarine.hpp"
#include <iostream>
class AssaultTerminator :public ISpaceMarine//사실상 무연산 클래스
{
	private:

	public:
		AssaultTerminator()
		{
			std::cout<< "* teleports from space *"<<std::endl;
		}
		virtual ~AssaultTerminator()
		{
			std::cout<< "I'll be back..."<<std::endl;
		}
		virtual ISpaceMarine* clone() const
		{
			ISpaceMarine *ret = new AssaultTerminator(*this);
			return ret;
		}
		virtual void battleCry() const
		{
			std::cout<< "This code is unclean. PURIFY IT!"<<std::endl;
		}
		virtual void rangedAttack() const
		{
			std::cout<< "* does nothing *"<<std::endl;
		}
		virtual void meleeAttack() const
		{
			std::cout<<  "* attacks with chainfists *"<<std::endl;
		}
};
#endif
