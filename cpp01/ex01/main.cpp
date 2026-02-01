#include "Zombie.hpp"

int main(void)
{
	int z = 5;
	Zombie *objs = zombieHorde(z, "maboulah");
	if (!objs)
		return (std::cout<<"new fail", 1);
	delete[] objs;
}