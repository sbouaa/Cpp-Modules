#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename X>
void    iter(X *arr, int len, void(*f)(const X &x))
{
    for (int i = 0; i < len; i++)
        f(arr[i]);
}

template <typename X>
void    iter(X *ar, int le, void(*fe)(X x))
{
    for (int i = 0; i < le; i++)
        fe(ar[i]);
}


#endif