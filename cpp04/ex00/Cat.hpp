#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat();
        Cat(const Cat &x);
        Cat& operator=(const Cat &x);
        ~Cat();
        void makeSound(void) const;
};

#endif