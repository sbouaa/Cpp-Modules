#include "RPN.hpp"

int main(int ac, char **av)
{
    RPN stack;
    (void)ac;
    stack.run(av[1]);
    // if (ac != 2)
    // {
    //     std::cout<<"Error : too much args\n";
    //     return 1;
    // }
    // RPN x;
    // try {
    //     x.run(av[1]);
    // }
    // catch (const std::exception &x)
    // {
    //     std::cout<<x.what();
    // }
}