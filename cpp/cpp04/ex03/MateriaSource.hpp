#ifndef __MATERIASOURCE__
#define __MATERIASOURCE__

#include "IMateriaSource.hpp"

class MateriaSource :public IMateriaSource
{
	private:
		AMateria *list[4];
		int count;
		int size;
	public:
		MateriaSource() :count(0), size(4)
		{
			for (int i = 0; i < 4; i++)
				this->list[i] = nullptr;
		}
		virtual ~MateriaSource()
		{
			for (int i = 0; i < size; i++)
				delete list[i];
		}
		MateriaSource(MateriaSource &src)
		{
			for (int i = 0; i < src.count; i++)
				this->learnMateria(src.list[i]->clone());
			for (int i = 0; i < 4; i++)
				this->list[i] = nullptr;
		}
		virtual void learnMateria(AMateria*src)
		{
			if (count < size && src != NULL)
				list[count++] = src;//이게 copy????
		}
		virtual AMateria* createMateria(std::string const & type)
		{
			int i = 0;
			while(i < count)
			{
				if (this->list[i]->getType() == type)
					return this->list[i]->clone();
				i++;
			}
			return NULL;
		}
};
#endif
