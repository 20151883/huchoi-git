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
		Character();
	public:
		Character(std::string const & name);
		Character &operator=(const Character &src);
		Character(const Character &src);
		~Character();
		void recoverAP();
		void equip(AWeapon* p_src);
		void attack(Enemy*opp);
		int getAp() const;
		const std::string getName() const;

		const AWeapon *getWeapon() const;
};

std::ostream &operator<<(std::ostream &ost, Character &src);

#endif
