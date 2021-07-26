#ifndef __RADSCORPION__
#define __RADSCORPION__

#include "Enemy.hpp"

class RadScorpion :public Enemy
{
	public:
		RadScorpion();
		~RadScorpion();
		RadScorpion(const RadScorpion &src);
		RadScorpion &operator=(const RadScorpion &src);
		void takeDamage(int num);
};
#endif
