#include "ICharacter.hpp"
#ifndef __AMATERIA__
#define __AMATERIA__
#include <iostream>

class ICharacter;
class Character;

class AMateria
{
	protected:
		//[...]
		std::string type;
		unsigned int _xp;
	public:
		AMateria(std::string const & type) :_xp(10), type(type)
		{}
		~AMateria() {}
		std::string const & getType() const
		{
			return this->type;
		}
		unsigned int getXP() const
		{
			return this->_xp;
		}
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
		virtual std::string getType()
		{
			return this->type;
		}
		void	addXp(int num = 10)
		{
			this->_xp += num;
		}
};

class Ice :public AMateria
{
	private:
		std::string sound;
	public:
		Ice() :AMateria("ice")
		{
			this->sound =  "* shoots an ice bolt at NAME *";
		}
		Ice(const Ice &src)  :AMateria("ice")
		{
			this->sound =  src.sound;
		}
		virtual std::string getType()
		{
			return this->type;
		}
		virtual void use(ICharacter& target)
		{
			addXp();
			std::cout<<this->sound<<std::endl;
		}
		virtual AMateria* clone() const
		{
			AMateria *ret = new Ice(*this);
			return ret;
		}
};

class Cure :public AMateria
{
	private:
		std::string sound;

	public:
		Cure() :AMateria("cure")
		{
			this->sound =  "* heals NAME’s wounds *";
		}
		Cure(const Cure &src)  :AMateria("cure")
		{
			this->sound =  src.sound;
		}
		virtual std::string getType()
		{
			return this->type;
		}
		virtual void use(ICharacter& target)
		{
			addXp();
			std::cout<<this->sound<<std::endl;
		}
		virtual AMateria* clone() const
		{
			AMateria *ret = new Cure(*this);
			return ret;
		}
};
#endif
