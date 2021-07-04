#include <iostream>
#ifndef _Weapon_
#define _Weapon_
class Weapon
{
	private:
		std::string type;
    public:
		Weapon(std::string init);
		void setType(std::string weapon_type);
		const std::string &getType();
};
#endif
