#ifndef __MATERIASOURCE__
# define __MATERIASOURCE__

# include "IMateriaSource.hpp"
# include <string>

class MateriaSource: public IMateriaSource
{
	private:
		int amount;
		AMateria *sources[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		virtual ~MateriaSource();

		MateriaSource &operator=(MateriaSource const &other);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const &type);
};
#endif
