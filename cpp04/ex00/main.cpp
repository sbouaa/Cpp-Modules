#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* a = new Animal();
    const Animal *b = new Cat();
    const Animal *c = new Dog();
    std::cout<<a->getType()<<std::endl;
    std::cout<<b->getType()<<std::endl;
    std::cout<<c->getType()<<std::endl;
    a->makeSound();
    b->makeSound();
    c->makeSound();
    delete a;
    delete c;
    delete b;
    std::cout<<"----------------------------\n";
    const WrongAnimal *a1 = new WrongAnimal();
    const WrongAnimal *c1 = new WrongCat();
    std::cout<<c1->getType()<<std::endl;
    a1->makeSound();
    c1->makeSound();
    delete a1;
    delete c1;
}
