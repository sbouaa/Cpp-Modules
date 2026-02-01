#ifndef AANIMAL_HPP 
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
    protected :
        std::string type;
    public :
        AAnimal();
        AAnimal(const AAnimal& x);
        AAnimal& operator=(const AAnimal &x);
        std::string getType(void) const;
        virtual void makeSound(void) const = 0;
        virtual ~AAnimal();
};

#endif