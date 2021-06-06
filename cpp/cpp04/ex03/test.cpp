#include <iostream>
class ICharacter;
class AMateria
{
	protected:
		//[...]
		std::string type;
		unsigned int _xp;
	public:
		AMateria(std::string const & type) :_xp(10)
		{

		}
		//[...]
		//[...]
		~AMateria() {}
		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materia's XP
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
		virtual std::string getType() = 0;
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
		virtual std::string getType()
		{
			return this->type;
		}
		virtual void use(ICharacter& target)
		{
			addXp();
			std::cout<<this->sound<<std::endl;
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
		virtual std::string getType()
		{
			return this->type;
		}
		virtual void use(ICharacter& target)
		{
			addXp();
			std::cout<<this->sound<<std::endl;
		}
};

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

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
			this->count = this->count > 0 ? this->count-1 : 0;//그냥 count만 감소시키면 될듯 delete하면 안되니까...
		}
		virtual void use(int idx, ICharacter& target)
		{

		}
};

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
		AMateria *	list[2];
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
					AMateria *ret = new AMateria(this->list[i]);
					return	ret;
				}
				else
					return NULL;
				i++;
			}
		}
};

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
