#ifndef __ICE__
#define __ICE__

#include "AMateria.hpp"

class Ice :public AMateria
{
	public:
		Ice();
		Ice(const Ice &src);
		Ice &operator=(Ice &src);
		~Ice();
		virtual void use(ICharacter& target);
		virtual AMateria* clone() const;
};
#endif
