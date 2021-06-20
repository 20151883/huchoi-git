#ifndef __SUPERMUTANT__
#define __SUPERMUTANT__

#include "Enemy.hpp"

class SuperMutant :public Enemy
{
	public:
		SuperMutant();
		virtual ~SuperMutant();
		SuperMutant(SuperMutant &src);
		SuperMutant &operator=(SuperMutant &src);
		virtual void takeDamage(int num);
};

#endif
