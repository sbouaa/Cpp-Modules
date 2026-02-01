#include "Zombie.hpp"

int main(void)
{
    Zombie obj1("SALAH");

    obj1.announce();
    std::cout << "=========newZombie====" << std::endl;
    Zombie *obj = newZombie("sbouaa");
    obj->announce();
    delete obj;

    std::cout << "==========randomChump========" << std::endl;
    
    randomChump("random SBOUAA");

}