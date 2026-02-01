#include "Cat.hpp"

Cat::Cat()
{
    std::cout<<"Cat default constructor called\n";
    type = "Cat";
    x = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal()
{
    std::cout<<"Cat copy constructor called\n";
    x = new Brain(*other.x);
    type = other.type;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout<<"Cat assignment operator called";
    if (this != &other)
    {
        delete x;
        x = new Brain(*other.x);
        type = other.type;
    }
    return *this;
}

void    Cat::makeSound(void) const
{
    std::cout<<"Meow\n";
}

Cat::~Cat()
{
    std::cout<<"Cat distructor called\n";
    delete x;
}