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

    bool            operator>(const Fixed& Other);
    bool            operator>=(const Fixed& Other);
    bool            operator<(const Fixed& Other);
    bool            operator<=(const Fixed& Other);
    bool            operator==(const Fixed& Other);
    bool            operator!=(const Fixed& Other);

    Fixed           operator+(const Fixed& Other) const;
    Fixed           operator-(const Fixed& Other) const;
    Fixed           operator*(const Fixed& Other) const;
    Fixed           operator/(const Fixed& Other) const;

    Fixed&  operator++();
    Fixed&  operator--();
    Fixed   operator++(int);
    Fixed   operator--(int);

    static Fixed& min(Fixed& One, Fixed& Other);
    static const Fixed& min(const Fixed& One, const Fixed& Other);
    static Fixed& max(Fixed& One, Fixed& Other);
    static const Fixed& max(const Fixed& One, const Fixed& Other);

    ~Fixed();
};

std::ostream&   operator<<(std::ostream& Os, const Fixed& Fx);


#endif