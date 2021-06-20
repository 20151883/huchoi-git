#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	//std::cout<<"*************"<<std::endl;
	//ISquad *test = new Squad(*vlc);
	delete vlc;
	//(*jim).battleCry();
	//std::cout<<"*************"<<std::endl;
	/*for (int i = 0; i < test->getCount(); ++i)
	{
		ISpaceMarine* cur = test->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete test;*/
	return 0;
}
