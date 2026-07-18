#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout<<"Error : could not open file.\n";
        return 1;
    }
    try
    {
        btc x(av[1]);
    }
    catch (std::exception &x)
    {
        std::cout<<x.what();
    }
}