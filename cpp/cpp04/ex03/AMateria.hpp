#ifndef __AMATERIA__
#define __AMATERIA__
#include <iostream>
#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
	protected:
		//[...]
		unsigned int _xp;
		std::string type;
		std::string sound;

	public:
		AMateria(std::string const & type):_xp(0), type(type)
		{}
		virtual ~AMateria() {}
		std::string const & getType() const
		{
			return this->type;
		}
		unsigned int getXP() const
		{
			return this->_xp;
		}
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target)
		{
			(void)target;
			this->_xp += 10;
		}
};

#endif
