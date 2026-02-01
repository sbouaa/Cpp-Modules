#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

void    Zombie::announce(void)
{
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::~Zombie()
{
    std::cout<<"destructor called ";
    std::cout<<name<< " !!!"<<std::endl;
}

void Zombie::setName(std::string s)
{
    name = s;
}
