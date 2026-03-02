#include "Base.hpp"

int main()
{
    std::srand(std::time(NULL));
    try 
    {
        Base *p = generate();
        Base *x = NULL;
        identify(p);
        identify(*x);
    }
    catch (std::exception &x)
    {
        x.what();
    }
}