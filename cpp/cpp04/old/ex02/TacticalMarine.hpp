#ifndef __TACTICALMARINE__
#define __TACTICALMARINE__

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine :public ISpaceMarine
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
