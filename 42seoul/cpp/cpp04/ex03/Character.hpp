#ifndef __CHARACTER__
#define __CHARACTER__

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character :public ICharacter
{
	private:
		std::string name;
		AMateria *slot[4];
		int count;
		int size;
		Character();
	public:
		Character(const char *name = "non name");
		~Character();
		Character(const Character &src);
		const Character &operator=(const Character &src);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		int getCount() const;
		int getSize() const;
};
#endif
