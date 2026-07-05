#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>

void    iter(T *arr, const int len, void (*f)(T &))
{
    if (!arr || !f)
        return ;
    for (int i = 0; i < len; i++)
        f(arr[i]);
}

template <typename X>
void    iter(const X *arr, const int len, void (*f)(const X &))
{
    if (!arr || !f)
        return ;
    for (int i = 0; i < len; i++)
        f(arr[i]);
}

#endif