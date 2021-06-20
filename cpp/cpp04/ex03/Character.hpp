#ifndef __CHARACTER__
#define __CHARACTER__

#include "ICharacter.hpp"

class Character :public ICharacter
{
	private:
		std::string name;
		AMateria *slot[4];
		int count;
		int size;
	public:
		Character(const char *name) :name(name), count(0), size(4)
		{}
		virtual ~Character() {}
		virtual std::string const & getName() const
		{
			return this->name;
		}
		virtual void equip(AMateria* m)
		{
			if (count < size)
				slot[count++] = m;
		}
		virtual void unequip(int idx)
		{
			if (this->slot[idx])
				this->slot[idx] = NULL;
			//this->count = this->count > 0 ? this->count-1 : 0;//그냥 count만 감소시키면 될듯 delete하면 안되니까...
		}
		virtual void use(int idx, ICharacter& target)
		{
			if (idx < count)
				this->slot[idx]->use(target);
		}
};
#endif
