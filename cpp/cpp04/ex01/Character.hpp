#include "AWeapon.hpp"
class Character
{
	private:
		std::string name;
		int ap;
		AWeapon *ptr;
	public:
		Character(std::string const & name) :ap(40),
		{

		}
		~Character()
		{

		}
		void recoverAP()
		{
			this->ap += 10;
		}
		void equip(AWeapon*);
		void attack(Enemy*)
		{
			if (ap가 적거나 없을떄)
		}
		std::string [...] getName() const;
};
