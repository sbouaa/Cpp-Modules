#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> 
{
    public :
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &x) : std::stack<T>(x) {}
        MutantStack& operator=(const MutantStack &x)
        {
            if (this != &x)
                std::stack<T>::operator=(x);
            return *this;
        }
        typedef typename std::deque<T>::iterator iterator;
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        ~MutantStack() {};
};

#endif