#include "Dog.hpp"

Dog::Dog()
{
    std::cout<<"Dog default constructor called\n";
    type = "Dog";
}

Dog::Dog(const Dog &x) : Animal()
{
    std::cout<<"Dog copy constructor called\n";
    type = x.type;
}

Dog& Dog::operator=(const Dog &x)
{
    std::cout<<"Dog assignment operator called";
    if (this != &x)
        type = x.type;
    return *this;
}

void    Dog::makeSound(void) const
{
    std::cout<<"Woef\n";
}

Dog::~Dog()
{
    std::cout<<"Dog destructor called\n";
}