#include "HumanA.hpp"

HumanA::HumanA(std::string  s, Weapon &w) : name(s) , w(w) {}

void    HumanA::attack()
{
    std::cout<<name<<" attacks with their "<<w.getType()<<std::endl;
}
