#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat();
        WrongCat(const WrongCat& x);
        WrongCat& operator=(const WrongCat& x);
        void    makeSound(void) const;
        ~WrongCat();
};

#endif