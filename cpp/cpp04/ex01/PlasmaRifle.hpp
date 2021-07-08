#ifndef __PLASMARIFLE__
#define __PLASMARIFLE__

#include "AWeapon.hpp"

class PlasmaRifle :public AWeapon
{
	public:
		PlasmaRifle();
		~PlasmaRifle();
		PlasmaRifle(const PlasmaRifle &src);
		PlasmaRifle &operator=(const PlasmaRifle &src);
		virtual void	attack() const;
};
#endif
