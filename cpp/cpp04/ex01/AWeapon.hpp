#ifndef __AWEAPON__
#define __AWEAPON__

#include <iostream>

class AWeapon
{
	protected:
		std::string name;
		std::string sound;
		int			apcost;
		int			damage;
		AWeapon();
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(const AWeapon &src);
		~AWeapon();
		AWeapon &operator=(const AWeapon &src);
		std::string getName() const;
		virtual int getAPCost() const;
		virtual int getDamage() const;
		virtual void attack() const = 0;
};
#endif
