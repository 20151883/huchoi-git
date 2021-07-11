#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Character.hpp"

int main()//객체간의 상호작용에 대해 공부하자.
{
	Character* me = new Character("me");
	std::cout << *me;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);//이 함수안에서 delete b가 수행될텐데, 이게 좋은 코드인가...? 대안은 어떤것이 있는지?
	std::cout << *me;
	
	delete me;
	//delete b;
	delete pr;
	delete pf;

	return 0;
}
