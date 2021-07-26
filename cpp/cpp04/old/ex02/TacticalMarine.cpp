#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
    std::cout<<"Tactical Marine ready for battle!"<<std::endl;
}

TacticalMarine::~TacticalMarine()
{
    std::cout<< "Aaargh..."<<std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &src)
{
    (void)src;
    std::cout<<"Tactical Marine ready for battle!"<<std::endl;
}

const TacticalMarine &TacticalMarine::operator=(const TacticalMarine &src)
{
   (void)src;
    return (*this);
}

ISpaceMarine *TacticalMarine::clone() const
{
    ISpaceMarine *ret = new TacticalMarine(*this);
    return ret;
}

void TacticalMarine::battleCry() const
{
    std::cout<<"For the holy PLOT!"<<std::endl;
}

void TacticalMarine::rangedAttack() const
{
    std::cout<< "* attacks with a bolter *"<<std::endl;
}

void TacticalMarine::meleeAttack() const
{
    std::cout<< "* attacks with a chainsword *"<<std::endl;
}