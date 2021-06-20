#ifndef __CHARACTER__
#define __CHARACTER__

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
		std::string name;
		int ap;
		AWeapon *ptr;
	public:
		Character(std::string const & name);
		~Character();
		void recoverAP();
		void equip(AWeapon* p_src);
		void attack(Enemy*opp);
		int getAp();
		std::string getName() const;
		AWeapon *getWeapon();
};

std::ostream &operator<<(std::ostream &ost, Character &src);

#endif
