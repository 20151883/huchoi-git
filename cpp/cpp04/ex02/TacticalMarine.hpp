#ifndef __TACTICALMARINE__
#define __TACTICALMARINE__

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine :public ISpaceMarine//왜 이 클래스에 대한 부모클래스를 인터페이스 클래스로 둔 것인지...? 확장을 안해서 그런가?
{
	private:

	public:
		TacticalMarine();
		~TacticalMarine();
		TacticalMarine(const TacticalMarine &src);
		const TacticalMarine &operator=(const TacticalMarine &src);
		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};
#endif
