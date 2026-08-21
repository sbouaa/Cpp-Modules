#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class NoOccurrence : public std::exception
{
    public :
        const char *what() const throw()
        {
            return "No occurrence is founded!!\n";
        }
};

template <typename T>
void    easyfind(T &x, int n)
{
    typename T::iterator i = std::find(x.begin(), x.end(), n);
    if (i == x.end())
        throw NoOccurrence();
    std::cout<<"Founded !!!!!!!  "<<"["<< *i <<"]";
}

#endif