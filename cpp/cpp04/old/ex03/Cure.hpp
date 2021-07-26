#ifndef __CURE__
#define __CURE__

#include "AMateria.hpp"

class Cure :public AMateria
{
	public:
		Cure();
		Cure(const Cure &src);
		Cure &operator=(Cure &src);
		~Cure();
		virtual void use(ICharacter& target);
		virtual AMateria* clone() const;
};
#endif
