#ifndef __IMATERIASOURCE__
#define __IMATERIASOURCE__

#include "AMateria.hpp"
#include <iostream>
class ICharacter;
class AMateria;

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
#endif
