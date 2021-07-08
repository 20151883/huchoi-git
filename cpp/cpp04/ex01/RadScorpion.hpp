#ifndef __RADSCORPION__
#define __RADSCORPION__

#include "Enemy.hpp"

class RadScorpion :public Enemy
{
	public:
		RadScorpion();
		virtual ~RadScorpion();
		RadScorpion(const RadScorpion &src);
		RadScorpion &operator=(const RadScorpion &src);
		virtual void takeDamage(int num);
};
#endif
