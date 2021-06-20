#ifndef __TACTICALMARINE__
#define __TACTICALMARINE__

#include "ISpaceMarine.hpp"
#include <iostream>
class TacticalMarine :public ISpaceMarine//사실상 무연산 클래스
{
	private:

	public:
		TacticalMarine()
		{
			std::cout<<"Tactical Marine ready for battle!"<<std::endl;
		}
		virtual ~TacticalMarine()
		{
			std::cout<< "Aaargh..."<<std::endl;
		}
		virtual ISpaceMarine* clone() const
		{
			ISpaceMarine *ret = new TacticalMarine(*this);
			return ret;
		}
		virtual void battleCry() const
		{
			std::cout<<"For the holy PLOT!"<<std::endl;
		}
		virtual void rangedAttack() const
		{
			std::cout<< "* attacks with a bolter *"<<std::endl;
		}
		virtual void meleeAttack() const
		{
			std::cout<< "* attacks with a chainsword *"<<std::endl;
		}
};
#endif
