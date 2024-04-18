#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class   Fixed
{
    private:

    int                 _value;
    static const int    _fractional = 8;

    public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

    Fixed(const int coint);
    Fixed(const float float_value);

    float   toFloat( void ) const;
    int     toInt( void ) const;

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    ~Fixed();
};

std::ostream& operator<<(std::ostream& Os, const Fixed& Fx);

#endif