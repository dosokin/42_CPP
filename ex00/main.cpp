#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments!" << std::endl;
        return (1);
    }
    try {
        ScalarConverter::convert(argv[1]);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}