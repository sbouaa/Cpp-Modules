#include "easyfind.hpp"

int main()
{
    std::vector <int> vec(20);
    std::vector <int>::iterator i;
    int x = 2;
    for (i = vec.begin(); i != vec.end(); i++)
    {
        *i = x * 2;
        x++;
    }
    try {
        easyfind(vec, 16);
    }
    catch (std::exception &x)
    {
        std::cout<<x.what();
    }
    return 0;
}
