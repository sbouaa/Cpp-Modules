#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout<<"FragTrap default constructor called\n";
    name = "";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
    std::cout<<"FragTrap parametrized constructor called\n";
    this->name = name;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &x) : ClapTrap()
{
    std::cout<<"FragTrap copy constructor called\n";
    *this = x;
}

void FragTrap::highFivesGuys(void)
{
    std::cout<<"Highfives\n";
}

void    FragTrap::attack(const std::string &target)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout<<"FragTrap "<<name<<" can't attack\n";
        return ;
    }
    energyPoints--;
    std::cout<<"FragTrap "<<name<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage\n";
}

FragTrap& FragTrap::operator=(const FragTrap &x)
{
    std::cout<<"FragTrap Assignment operator called\n";
    if (this != &x)
    {
        name = x.name;
        hitPoints = x.hitPoints;
        energyPoints = x.energyPoints;
        attackDamage = x.attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout<<"FragTrap distructor called\n";
}