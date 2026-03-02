#include "Base.hpp"

int main()
{
    std::srand(std::time(0));
    Base *p = generate();
    identify(*p);
    identify(p);
}