#include "Fixed.hpp"

Fixed::Fixed() : number(0) {}

Fixed::Fixed(const Fixed &x) : number(x.number) {}

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
    if (this != &x)
        number = x.number;
    return *this;
}

int Fixed::getRawBits(void) const
{
    return number;
}

void Fixed::setRawBits(int const raw)
{
    number = raw;   
}

Fixed::~Fixed() {}

std::ostream& operator<<(std::ostream &c, const Fixed& obj)
{
    c << obj.toFloat();
    return c;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed temp;
    temp.number = this->number + other.number;
    return temp;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed temp;
    temp.number = this->number - other.number;
    return temp;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed temp(this->toFloat() * other.toFloat());
    return temp;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed temp(this->toFloat() / other.toFloat());
    return temp;
}

Fixed  Fixed::operator++(int)
{
    Fixed temp(*this);
    this->number++;
    return temp;
}

Fixed  Fixed::operator--(int)
{
    Fixed temp(*this);
    this->number--;
    return temp;
}

Fixed& Fixed::operator++()
{
    number++;
    return *this;
}

Fixed& Fixed::operator--()
{
    number--;
    return *this;
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->number == other.number);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->number != other.number);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->number < other.number);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->number > other.number);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->number <= other.number);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->number >= other.number);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

