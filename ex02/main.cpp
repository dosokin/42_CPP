#include <iostream>
#include "Base.hpp"
#include <cstdlib>

int main(){

    Base *la_base;
    std::srand(time(NULL));
    for (size_t i = 0; i < 20; i++){
        la_base = generate();
        std::cout << "Pointer identify = ";
        identify(la_base);
        std::cout << "Reference identify = ";
        identify(*la_base);
        delete la_base;
        std::cout << std::endl;
    }
    return (0);
}