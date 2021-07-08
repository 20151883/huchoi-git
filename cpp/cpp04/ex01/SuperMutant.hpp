#ifndef __SUPERMUTANT__
#define __SUPERMUTANT__

#include "Enemy.hpp"

class SuperMutant :public Enemy
{
	public:
		SuperMutant();
		virtual ~SuperMutant();
		SuperMutant(const SuperMutant &src);
		SuperMutant &operator=(const SuperMutant &src);
		virtual void takeDamage(int num);
};

#endif
