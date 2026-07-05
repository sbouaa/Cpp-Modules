#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private :
        T *arr;
        unsigned int len;
    public :
        Array();
        Array(unsigned int n);
        Array(const Array &x);
        Array& operator=(const Array &x);
        T& operator[](unsigned int index);
        class CheckIndex : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return "index out of bounds\n";
                }
        };
        unsigned int size(void) const;
        ~Array();
};


#include "Array.tpp"
#endif