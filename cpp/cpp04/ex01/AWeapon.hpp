#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{
	protected:
		std::string name;
		int			apcost;
		int			damage;
		AWeapon();
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(const AWeapon &src);
		virtual ~AWeapon();
		AWeapon &operator=(const AWeapon &src);
		const std::string &getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;
};
#endif
