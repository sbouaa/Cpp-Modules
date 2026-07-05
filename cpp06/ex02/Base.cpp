#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate(void)
{
    int x = std::rand() % 3;
    if (x == 0)
        return new A();
    if (x == 1)
        return new B();
    else
        return new C();
}

void    identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout<<"is A\n";
    if (dynamic_cast<B*>(p))
        std::cout<<"is B\n";
    if (dynamic_cast<C*>(p))
        std::cout<<"is C\n";
    else
        std::cout<<"unknown type\n";
}

void    identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout<<"is A\n";
        return ;
    }
    catch (...){}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout<<"is B\n";
        return ;
    }
    catch (...){}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout<<"is C\n";
        return ;
    }
    catch (...){
        std::cout<<"unknown type\n";
    }
}