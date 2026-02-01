#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap
{
    private:
        std::string name;
        long hitPoints;
        long energyPoints;
        long attackDamage;
    public:
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