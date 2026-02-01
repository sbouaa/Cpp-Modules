#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout<<"WrongCat default constuctor called\n";
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& x) : WrongAnimal()
{
    std::cout<<"WrongCat copy constructor called\n";
    type = x.type;
}

WrongCat& WrongCat::operator=(const WrongCat& x)
{
    std::cout<<"WrongCat assignment operator called\n";
    if (this != &x)
        type = x.type;
    return *this;
}

void    WrongCat::makeSound(void) const
{
    std::cout<<"Meow\n";
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat distructor called\n";
}