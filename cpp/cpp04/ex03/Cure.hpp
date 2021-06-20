#ifndef __CURE__
#define __CURE__

#include "AMateria.hpp"

class Cure :public AMateria
{
	public:
		Cure() :AMateria("cure")
		{
			this->sound =  "* heals ";
		}
		Cure(const Cure &src)  :AMateria("cure")
		{
			this->sound =  src.sound;
		}
		Cure &operator=(Cure &src)
		{
			(void)src;
			return *this;
		}
		~Cure()
		{

		}
		virtual void use(ICharacter& target)
		{
			AMateria::use(target);
			std::cout<<this->sound<<target.getName()<<"’s wounds *"<<std::endl;//target.getName()
		}
		virtual AMateria* clone() const
		{
			AMateria *ret = new Cure(*this);
			return ret;
		}
};
#endif
