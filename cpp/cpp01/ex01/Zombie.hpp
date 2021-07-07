#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string input_name="non name");
		void announce(void);
		void    setZomnieName(std::string name);
		~Zombie();
};
#endif
