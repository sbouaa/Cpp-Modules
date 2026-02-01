#include "HumanB.hpp"

HumanB::HumanB(std::string  s) : name(s) ,weapon(NULL) {}

void    HumanB::setWeapon(Weapon &w)
{
    this->weapon = &w;
}

void    HumanB::attack()
{
    if (weapon)
        std::cout<<name<<" attacks with their "<<weapon->getType()<<std::endl;
    else
        std::cout<<" has no weapon "<<std::endl;
}
