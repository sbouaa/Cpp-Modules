#include "Dog.hpp"

Dog::Dog()
{
    std::cout<<"Dog default constructor called\n";
    type = "Dog";
    x = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal()
{
    std::cout<<"Dog copy constructor called\n";
    x = new Brain(*other.x);
    type = other.type;
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout<<"Dog assignment operator called";
    if (this != &other)
    {
        type = other.type;
        delete x;
        x = new Brain(*other.x);
    }
    return *this;
}

void    Dog::makeSound(void) const
{
    std::cout<<"Woef\n";
}

Dog::~Dog()
{
    std::cout<<"Dog distructor called\n";
    delete x;
}