#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("")
{
    std::cout<<"WrongAnimal default constuctor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& x)
{
    std::cout<<"WrongAnimal copy constructor called\n";
    type = x.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& x)
{
    std::cout<<"WrongAnimal assignment operator called\n";
    if (this != &x)
        type = x.type;
    return *this;
}

std::string WrongAnimal::getType(void) const
{
    return type;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout<<"WrongAnimal\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal destructor called\n";
}