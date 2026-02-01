#include "Animal.hpp"

Animal::Animal() : type("") 
{
    std::cout<<"Animal Default constructor called\n";
};

Animal::Animal(const Animal &x)
{
    std::cout<<"Animal copy constructor called\n";
    type = x.type;
}

Animal& Animal::operator=(const Animal &x)
{
    std::cout<<"Animal assignment operator called\n";
    if (this != &x)
        type = x.type;
    return *this;
}

void    Animal::makeSound(void) const
{
    std::cout<<"Animal\n";
}

std::string Animal::getType(void) const
{
    return type;
}

Animal::~Animal()
{
    std::cout<<"Animal destructor called\n";
}