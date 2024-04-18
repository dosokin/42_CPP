#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (&other != this)
    {
        this->_value = other.getRawBits();
    }
    return (*this);
}

Fixed::Fixed(const int int_value)
{
    std::cout << "Int constructor called" << std::endl;
    _value = int_value * 256;
}

Fixed::Fixed(const float float_value)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(float_value * 256.0);
}

int Fixed::getRawBits( void ) const
{
    return (_value);
}

void Fixed::setRawBits( int const raw )
{
    _value = raw;
}

float   Fixed::toFloat( void ) const
{
    return ((float)_value / 256.0);
}

int     Fixed::toInt( void ) const
{
    return (_value / 256);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& Os, const Fixed& Fx)
{
    Os << Fx.toFloat();
    return (Os);
}