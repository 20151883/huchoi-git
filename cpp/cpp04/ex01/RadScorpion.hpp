#ifndef __RADSCORPION__
#define __RADSCORPION__

#include "Enemy.hpp"

class RadScorpion :public Enemy
{
	public:
		RadScorpion();
		virtual ~RadScorpion();
		RadScorpion(RadScorpion &src);
		RadScorpion &operator=(RadScorpion &src);
		virtual void takeDamage(int num);
};
#endif
