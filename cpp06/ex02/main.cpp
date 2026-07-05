#include "Base.hpp"

int main()
{
    Base a;
    std::srand(std::time(0));
    Base *p = generate();
    identify(*p);
    identify(a);
}