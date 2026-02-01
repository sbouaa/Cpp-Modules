#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0) {std::cout<<"Default constructor called\n";}

ClapTrap::ClapTrap(std::string s) : name(s), hitPoints(10), energyPoints(10), attackDamage(0) {std::cout<<"Parameterized Constructor called\n";}

ClapTrap::ClapTrap(const ClapTrap &x)
{
    std::cout<<"ClapTrap copy contructor called\n";
    *this = x;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &x)
{
    std::cout<<"ClapTrap Assignment Operator called\n";
    if (this != &x)
    {
        name = x.name;
        hitPoints = x.hitPoints;
        energyPoints = x.energyPoints;
        attackDamage = x.attackDamage;
    }
    return *this;
}

void    ClapTrap::attack(const std::string &target)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout<<"ClapTrap "<<name<<" can't attack\n";
        return ;
    }
    energyPoints--;
    std::cout<<"ClapTrap "<<name<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage!\n";
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0)
    {
        hitPoints = 0;
        std::cout<<"Deid\n";
        return ;
    }
    std::cout<<"ClapTrap "<<name<<" takes "<<amount<<" Damage\n";
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout<<"ClapTrap "<<name<<" can't be repaired\n";
        return ;
    }
    hitPoints += amount;
    std::cout<<"ClapTrap "<<name<<" takes "<<amount<<" of hit points\n";
    energyPoints--;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"ClapTrap "<<name<<" distructor called\n";
}