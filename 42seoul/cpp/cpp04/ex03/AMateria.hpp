#ifndef __AMATERIA__
#define __AMATERIA__
#include <iostream>
#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
	protected:
		unsigned int _xp;
		std::string type;

	public:
		AMateria(std::string const & type = "non type");
		AMateria(const AMateria &src);
		const AMateria &operator=(const AMateria &src); 
		virtual ~AMateria();
		std::string const & getType() const;
		unsigned int getXP() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
