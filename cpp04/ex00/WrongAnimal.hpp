#ifndef WRONGANMAL_HPP
#define WRONGANMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected :
        std::string type;
    public :
        WrongAnimal();
        WrongAnimal(const WrongAnimal& x);
        WrongAnimal& operator=(const WrongAnimal& x);
        void    makeSound(void) const;
        std::string getType(void) const;
        ~WrongAnimal();
};


#endif
