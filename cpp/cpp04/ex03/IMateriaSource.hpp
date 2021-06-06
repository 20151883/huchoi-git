#include "AMateria.hpp"
#ifndef __IMATERIASOURCE__
#define __IMATERIASOURCE__
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

class MateriaSource :public IMateriaSource
{
	private:
		AMateria *list[2];
		int count;
		int size;
	public:
		MateriaSource() :count(0), size(2)
		{

		}
		virtual ~MateriaSource()
		{

		}
		virtual void learnMateria(AMateria*src)
		{
			if (count < size)
				list[count++] = src;
		}
		virtual AMateria* createMateria(std::string const & type)
		{
			int i = 0;
			while(i < count)
			{
				if (this->list[i]->getType() == type)
				{
					AMateria *ret = NULL;
					if (type == "ice")
						ret = new Ice();
					else
						ret = new Cure();
					return	ret;
				}
				i++;
			}
			return NULL;
		}
};
#endif
