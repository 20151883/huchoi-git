#ifndef __PEON__
#define __PEON__
#include <iostream>
#include "Victim.hpp"

class Peon : public Victim
{
	protected:
		Peon();
	public:
		Peon(const char *n);
		Peon(const Peon &src);
		void	 getPolymorphed() const;
		Peon	&operator=(Peon &src);
		~Peon();
};
#endif
