#ifndef __ICE__
#define __ICE__

#include "AMateria.hpp"

class Ice :public AMateria
{
	public:
		Ice() :AMateria("ice")
		{
			this->sound =  "* shoots an ice bolt at ";
		}
		Ice(const Ice &src)  :AMateria("ice")
		{
			this->sound =  src.sound;
		}
		Ice &operator=(Ice &src)
		{
			(void)src;
			return *this;
		}
		~Ice()
		{

		}
		virtual void use(ICharacter& target)
		{
			AMateria::use(target);
			std::cout<<this->sound<<target.getName()<<" *"<<std::endl;//target.getName()
		}
		virtual AMateria* clone() const
		{
			AMateria *ret = new Ice(*this);
			return ret;
		}
};
#endif
