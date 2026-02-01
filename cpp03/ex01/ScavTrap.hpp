#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(const std::string name);
        ScavTrap(const ScavTrap &x);
        ScavTrap &operator=(const ScavTrap &x);
        void    attack(const std::string &target);
        void guardGate();
        ~ScavTrap();
};

#endif