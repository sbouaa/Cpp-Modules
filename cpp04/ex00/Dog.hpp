#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public :
        Dog();
        Dog(const Dog &x);
        Dog& operator=(const Dog &x);
        ~Dog();
        void makeSound(void) const;
};

#endif