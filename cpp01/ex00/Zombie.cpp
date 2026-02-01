#include "Zombie.hpp"

Zombie::Zombie(std::string s) : name(s) {}

void    Zombie::announce(void)
{
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::~Zombie()
{
    std::cout<<"destructor called ";
    std::cout<<name<< " !!!"<<std::endl;
}