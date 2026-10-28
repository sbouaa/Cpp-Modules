#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        std::runtime_error("Error : usage ./PmergMe [Numbers]\n");
    try {
        PmergeMe x;
        x.check(ac, av);
        x.begin();
    }
    catch(std::exception &e)
    {
        std::cerr<< e.what();
    }
    return 0;
}