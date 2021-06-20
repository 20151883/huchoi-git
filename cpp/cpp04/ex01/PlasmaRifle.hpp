#ifndef __PLASMARIFLE__
#define __PLASMARIFLE__

#include "AWeapon.hpp"

class PlasmaRifle :public AWeapon
{
	public:
		PlasmaRifle();
		~PlasmaRifle();
		PlasmaRifle(PlasmaRifle &src);
		PlasmaRifle &operator=(PlasmaRifle &src);
		virtual void	attack() const;
};
#endif
