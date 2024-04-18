#ifndef FIXED_HPP
# define FIXED_HPP

class   Fixed
{
    private:

    int                 _value;
    static const int    _fractional = 8;

    public:
    Fixed();
    Fixed(Fixed& other);
    Fixed& operator=(Fixed& other);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    ~Fixed();
};

#endif