#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int number;
        static const int fract = 8;
    public:
        Fixed();
        Fixed(const int point);
        Fixed(const float point);
        Fixed(const Fixed &x);
        Fixed &operator=(const Fixed &x);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        ~Fixed();
};

std::ostream& operator <<(std::ostream &c, const Fixed& obj);

#endif