#ifndef __ENEMY__
#define __ENEMY__

#include <iostream>

class Enemy
{
	protected:
		int hp;
		std::string type;
		std::string dead;
		int flag;
		Enemy();
	public:
		Enemy(int hp, std::string const & type);
		virtual ~Enemy();
		Enemy(Enemy &src);
		Enemy &operator=(Enemy &src);
		std::string getType() const;
		int getHp() const;
		void setFlag(int num);
		int getFlag();
		virtual void takeDamage(int) = 0;
};
#endif
