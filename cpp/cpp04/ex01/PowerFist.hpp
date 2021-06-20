#ifndef __POWERFIST__
#define __POWERFIST__

#include "AWeapon.hpp"

class PowerFist :public AWeapon
{
	public:
		PowerFist();
		~PowerFist();
		PowerFist(PowerFist &src);
		PowerFist &operator=(PowerFist &src);
		virtual void	attack() const;
};
#endif
