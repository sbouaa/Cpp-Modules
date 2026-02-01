#include "Cat.hpp"

Cat::Cat()
{
    std::cout<<"Cat default constructor called\n";
    type = "Cat";
}

Cat::Cat(const Cat &x) : Animal()
{
    std::cout<<"Cat copy constructor called\n";
    type = x.type;
}

Cat& Cat::operator=(const Cat &x)
{
    std::cout<<"Cat assignment operator called";
    if (this != &x)
        type = x.type;
    return *this;
}

void    Cat::makeSound(void) const
{
    std::cout<<"Meow\n";
}

Cat::~Cat()
{
    std::cout<<"Cat destructor called\n";
}