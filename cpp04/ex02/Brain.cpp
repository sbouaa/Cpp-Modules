#include "Brain.hpp"

Brain::Brain()
{
    std::cout<<"Brain default constructor called\n";
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
}

Brain::Brain(const Brain &x)
{
    std::cout<<"Brain copy constructor called\n";
    *this = x;
}

Brain& Brain::operator=(const Brain &x)
{
    std::cout<<"Brain assignment operator called\n";
    if (this != &x)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = x.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout<<"Brain distructor called\n";
}