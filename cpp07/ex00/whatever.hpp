#ifndef X_HPP
#define X_HPP

#include <iostream>
#include <string>

template <typename Q>
void    swap(Q &x, Q &y)
{
    Q tmp = x;
    x = y;
    y = tmp;
}

template <typename Q>
Q min(Q x, Q y)
{
    if (x < y)
        return x;
    return y;
}

template <typename Q>
Q max(Q x, Q y)
{
    if (x > y)
        return x;
    return y;
}

#endif