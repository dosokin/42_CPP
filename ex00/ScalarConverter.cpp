#include "ScalarConverter.hpp"
#include "utils.h"
#include <iostream>
#include <sstream>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

input_info  isArgValid(std::string og)
{
    input_info info = {.entire=0,.decimal=0,.round=true,.type=UNKNOWN};
    int     i = 0;

    if (og.empty()) {
        std::cerr << "Conversion from nothing isn't possible" << std::endl;
        info.type = ERR;
        return (info);
    };
    info.type = isSpecial(og);
    if (info.type != UNKNOWN)
        return info;
    if (isAlpha(og[i])) {
        if (og.length() != 1) {
            std::cerr << "Only scalar types accepted as argument" << std::endl;
            info.type = ERR;
            return (info);
        }
        info.type = CHAR;
        return (info);
    }
    if (og[i] == '-' || og[i] == '+')
        ++i;
    for (;isDigit(og[i]); i++){info.entire++;}
    if (og[i] == 0) {
        info.type = INT;
        return (info);
    }
    else if (og[i] == '.')
        i++;
    else {
        info.type = UNKNOWN;
        return (info);
    }
    if (og[i] == 0 || og[i] == 'f')
    {
        info.type = UNKNOWN;
        return (info);
    }
    for (;isDigit(og[i]); i++){info.decimal++; if (og[i] != '0'){info.round = false;}}
    if (og[i] == 0)
    {
        info.type = DOUBLE;
        return (info);
    }
    else if (og[i] == 'f')
    {
        if (og[i + 1] == 0)
        {
            info.type = FLOAT;
            return (info);
        }
    }
    info.type = UNKNOWN;
    return (info);
}

void    ScalarConverter::convert(std::string og)
{
    input_info info = {};
    e_type type;
    int     i;
    float   f;
    double  d;

    info = isArgValid(og);
    type = info.type;
    switch (type){
        case (ERR) :
            return ;
        case (UNKNOWN) : {
            std::cerr << "Invalid arg" << std::endl;
            break;
        }
        case (INT) :
        {
            std::istringstream(og) >> i;
            if ((i == MAX_INT && og != "2147483647") || (i == MIN_INT && og != "-2147483648")){
                std::cerr << "INT OVERFLOW" << std::endl;
                return ;
            }
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            if (i >= 32 && i <= 126)
                std::cout << "char : " <<  static_cast<char>(i) << std::endl;
            else
                std::cout << "char : Non displayable" << std::endl;
            std::cout << "int : " << i << std::endl;
            std::cout << "float : " << f << ".0f" << std::endl;
            std::cout << "double : " << d << ".0" << std::endl;
            break ;
        }
        case (DOUBLE) :
        {
            std::istringstream(og) >> d;
            f = static_cast<float>(d);
            i = static_cast<int>(d);
            if (d >= 32.0 && d <= 126.0)
                std::cout << "char : " <<  static_cast<char>(i) << std::endl;
            else
                std::cout << "char : Non displayable" << std::endl;
            std::cout << "int : " << i << std::endl;
            if (info.round)
            {
                std::cout << "float : " << f << ".0f" << std::endl;
                std::cout << "double : " << d << ".0" << std::endl;
            }
            else
            {
                std::cout << "float : " << f << "f" << std::endl;
                std::cout << "double : " << d << std::endl;
            }
            break ;
        }
        case (FLOAT) :
        {
            std::istringstream(og) >> f;
            d = static_cast<double>(f);
            i = static_cast<int>(f);
            if (f >= 32.0f && f <= 126.0f)
                std::cout << "char : " <<  static_cast<char>(i) << std::endl;
            else
                std::cout << "char : Non displayable" << std::endl;
            std::cout << "int : " << i << std::endl;
            if (info.round)
            {
                std::cout << "float : " << f << ".0f" << std::endl;
                std::cout << "double : " << d << ".0" << std::endl;
            }
            else
            {
                std::cout << "float : " << f << "f" << std::endl;
                std::cout << "double : " << d << std::endl;
            }
            break ;
        }
        case (CHAR) :
        {
            i = static_cast<int>(og[0]);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            std::cout << "char : " << og << std::endl;
            std::cout << "int : " << i << std::endl;
            std::cout << "float : " << f << ".0f" << std::endl;
            std::cout << "double : " << d << ".0" << std::endl;
            break ;
        }
        case (NAN) : {
            std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
            break ;
        }
        case (MINUSINF) : {
            std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
            break ;
        }
        case (PLUSINF) : {
            std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
            break ;
        }
    }
}

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter &Other){
    (void)Other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter &Other){
    (void)Other;
    return (*this);
}

ScalarConverter::~ScalarConverter(){}