#include "Fixed.hpp"

Fixed::Fixed() : number(0) {std::cout<<"Default constructor called\n";}

Fixed::Fixed(const Fixed &x) : number(x.number) {std::cout<<"Copy constructor called\n";}

Fixed::Fixed(const int point)
{
    number = point << fract;
}

int Fixed::toInt(void) const
{
    return (number >> fract);
}

Fixed::Fixed(const float point)
{
    number = roundf(point * (1 << fract));
}

float Fixed::toFloat(void) const
{
    return (number / (float)(1 << fract));
}

Fixed &Fixed::operator=(const Fixed &x)
{
    std::cout<<"Copy assignment operator called\n";
    if (this != &x)
        number = x.number;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called\n";
    return number;
}

void Fixed::setRawBits(int const raw)
{
    std::cout<<"setRawBits member function called\n";
    number = raw;   
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called\n";
}

std::ostream& operator <<(std::ostream &c, const Fixed& obj)
{
    c << obj.toFloat();
    return c;
}
