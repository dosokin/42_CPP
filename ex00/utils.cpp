#include <string>
#include "utils.h"

e_type isSpecial(std::string og)
{
    if (og == "nanf" || og == "nan")
        return (NAN);
    else if (og == "-inff" || og == "-inf")
        return (MINUSINF);
    else if (og == "+inff" || og == "+inf")
        return (PLUSINF);
    return (UNKNOWN);
}

bool    isAlpha(char c)
{
    if (c >= 65 && c <= 90)
        return (true);
    if (c >= 97 && c <= 122)
        return (true);
    return (false);
}

bool    isDigit(char c)
{
    if (c >= 48 && c <= 57)
        return (true);
    return (false);
}
