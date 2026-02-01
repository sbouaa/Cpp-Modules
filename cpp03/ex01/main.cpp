#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("fassi");
    ScavTrap b("Azerty");
    a.attack("Qwerty");
    b.beRepaired(300);
    b.attack("fassi");
    a.takeDamage(6000);
    a.guardGate();
}