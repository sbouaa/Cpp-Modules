#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout<<"ScavTrap default constructor called\n";
    name = "";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    std::cout<<"ScavTrap parametrized constructor called\n";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &x) : ClapTrap()
{
    std::cout<<"ScavTrap copy constructor called\n";
    *this = x;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &x)
{
    std::cout<<"ScavTrap Assignment oprerator called\n";
    if (this != &x)
    {
        name = x.name;
        energyPoints = x.energyPoints;
        hitPoints = x.hitPoints;
        attackDamage = x.attackDamage;
    }
    return *this;
}

void    ScavTrap::attack(const std::string &target)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout<<"ScavTrap "<<name<<" can't attack\n";
        return ;
    }
    energyPoints--;
    std::cout<<"ScavTrap "<<name<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage\n";
}

void    ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<name<<" is now in Gate keeper mode\n";
}

ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap distructor called\n";
}