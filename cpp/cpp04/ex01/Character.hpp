#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

class Character
{
	private:
		std::string name;
		int ap;
		const AWeapon *ptr;
		Character();
	public:
		Character(std::string const & name);
		Character &operator=(const Character &src);
		Character(const Character &src);
		~Character();
		void recoverAP();
		void equip(AWeapon* p_src);
		void attack(Enemy*opp);//생각해보니 매개변수 자료형을 const Ememy * 로 하는건 불필요한 일이었음.
		int getAp() const;
		const std::string getName() const;

		const AWeapon *getWeapon() const;
};

std::ostream &operator<<(std::ostream &ost, Character &src);

#endif
