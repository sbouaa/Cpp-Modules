#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap
{
    protected :
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public :
        ClapTrap();
        ClapTrap(std::string s);
        ClapTrap(const ClapTrap &x);
        ClapTrap &operator=(const ClapTrap &x);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        ~ClapTrap();
};

#endif