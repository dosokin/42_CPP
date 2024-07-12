#include <iostream>
#include "Array.hpp"

int main(){
    Array<int> gerard;
    Array<int> five(5);
    Array<int> fourty_two(42);
    Array<char> character(2);
    Array<std::string> charact(2);

    five[3] = 42;
    character[0] = 'y';
    charact[0] = "test abc";

    std::cout << character[0] << std::endl;
    std::cout << charact[1] << std::endl;
    std::cout << charact[0] << std::endl;
    std::cout << std::endl;
    try{
        std::cout << five[0] << std::endl;
        std::cout << five[1] << std::endl;
        std::cout << five[2] << std::endl;
        std::cout << five[3] << std::endl;
        std::cout << five[4] << std::endl;
        std::cout << five[5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << gerard[89] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}