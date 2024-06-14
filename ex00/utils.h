#ifndef UTILS_H
#define UTILS_H

enum e_type{
    NAN,
    PLUSINF,
    MINUSINF,
    ERR,
    UNKNOWN,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

struct input_info {
    int entire;
    int decimal;
    bool round;
    e_type type;
};

e_type isSpecial(std::string og);
bool    isAlpha(char c);
bool    isDigit(char c);

#endif
