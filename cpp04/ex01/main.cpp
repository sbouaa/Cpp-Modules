#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal *x[4];
    for (int i = 0; i < 4; i++)
    {
        if (i > 1)
            x[i] = new Cat();
        else
            x[i] = new Dog();
        x[i]->makeSound();
    }
    for (int i =0; i <4; i++)
    {
        delete x[i];
        std::cout<<"____________________\n";
    }
    return 0;
}