#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <stdexcept>

class ScalarConverter {
public:
    static void    convert(std::string og);
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter &Other);
    ScalarConverter& operator=(ScalarConverter &Other);
    ~ScalarConverter();
};

#endif
