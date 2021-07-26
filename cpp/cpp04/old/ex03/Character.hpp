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
		int size;//확장성을 위해 이걸 변수로 두는게 맞겠다.(슬롯의 개수가 4->5가 될수도 있으니까...)유지보수의 편리를 위해서
		Character();
	public:
		Character(const char *name);
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
