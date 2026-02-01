#include "AAnimal.hpp"

AAnimal::AAnimal() : type("") 
{
    std::cout<<"AAnimal Default constructor called\n";
};

AAnimal::AAnimal(const AAnimal &x)
{
    std::cout<<"AAnimal copy constructor called\n";
    type = x.type;
}

AAnimal& AAnimal::operator=(const AAnimal &x)
{
    std::cout<<"AAnimal assignment operator called\n";
    if (this != &x)
        type = x.type;
    return *this;
}

std::string AAnimal::getType(void) const
{
    return type;
}

AAnimal::~AAnimal()
{
    std::cout<<"AAnimal distructor called\n";
}