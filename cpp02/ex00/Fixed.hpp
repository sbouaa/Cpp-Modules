#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int number;
        static const int fract = 8;
    public:
        Fixed();
        Fixed(const Fixed &x);
        Fixed &operator=(const Fixed &x);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        ~Fixed();
};

#endif