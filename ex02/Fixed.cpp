#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    _value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    this->_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (&other != this)
    {
        this->_value = other.getRawBits();
    }
    return (*this);
}

Fixed::Fixed(const int int_value)
{
    _value = int_value * 256;
}

Fixed::Fixed(const float float_value)
{
    _value = roundf(float_value * 256.0f);
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
    return ((float)_value / 256.0f);
}

int     Fixed::toInt( void ) const
{
    return (_value / 256);
}

Fixed::~Fixed()
{
}

std::ostream& operator<<(std::ostream& Os, const Fixed& Fx)
{
    Os << Fx.toFloat();
    return (Os);
}

bool            Fixed::operator>(const Fixed& Other)
{
    return (this->toFloat() > Other.toFloat());
}

bool            Fixed::operator>=(const Fixed& Other)
{
    return (this->toFloat() >= Other.toFloat());
}

bool            Fixed::operator<(const Fixed& Other)
{
    return (this->toFloat() < Other.toFloat());
}

bool            Fixed::operator<=(const Fixed& Other)
{
    return (this->toFloat() <= Other.toFloat());
}

bool            Fixed::operator==(const Fixed& Other)
{
    return (this->toFloat() == Other.toFloat());
}

bool            Fixed::operator!=(const Fixed& Other)
{
    return (this->toFloat() != Other.toFloat());
}

Fixed            Fixed::operator+(const Fixed& Other) const
{
    Fixed   Fxbis(this->toFloat() + Other.toFloat());
    return (Fxbis);
}

Fixed            Fixed::operator-(const Fixed& Other) const
{
    Fixed   Fxbis(this->toFloat() - Other.toFloat());
    return (Fxbis);
}

Fixed            Fixed::operator/(const Fixed& Other) const
{
    Fixed   Fxbis(this->toFloat() / Other.toFloat());
    return (Fxbis);
}

Fixed           Fixed::operator*(const Fixed& Other) const
{
    Fixed   Fxbis(float(this->toFloat() * Other.toFloat()));
    return (Fxbis);
}

Fixed& Fixed::operator++()
{
    this->setRawBits(getRawBits() + 1);
    return (*this);
}

Fixed& Fixed::operator--()
{
    this->setRawBits(getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed FxBis(*this);
    this->setRawBits(this->getRawBits() + 1);
    return (FxBis);
}

Fixed Fixed::operator--(int)
{
    Fixed FxBis(*this);
    this->setRawBits(this->getRawBits() - 1);
    return (FxBis);
}

Fixed& Fixed::min(Fixed& One, Fixed& Other)
{
    if (One < Other)
        return One;
    return Other;
}

const Fixed& Fixed::min(const Fixed& One, const Fixed& Other)
{
    Fixed   OneBis(One);
    Fixed   OtherBis(Other);

    if (OneBis < OtherBis)
        return One;
    return Other;
}

Fixed& Fixed::max(Fixed& One, Fixed& Other)
{
    if (One > Other)
        return One;
    return Other;
}

const Fixed& Fixed::max(const Fixed& One, const Fixed& Other)
{
    Fixed   OneBis(One);
    Fixed   OtherBis(Other);

    if (OneBis > OtherBis)
        return One;
    return Other;
}
