#ifndef ANIMAL_HPP 
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected :
        std::string type;
    public :
        Animal();
        Animal(const Animal& x);
        Animal& operator=(const Animal &x);
        std::string getType(void) const;
        virtual void makeSound(void) const;
        virtual ~Animal();
};

#endif