#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl obj;
    if (ac != 2)
    {
        std::cerr<<"Error" << std::endl;
        return (1);
    }
    else
    {
        std::string level = av[1];
        obj.complain(level);
    }
    return 0;
}