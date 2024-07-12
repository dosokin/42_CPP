#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void printFunction(T type){
    std::cout << type << std::endl;
}

template<typename T>
void incrementAndPrintFunction(T type){
    type++;
    std::cout << type << std::endl;
}

template<typename T, typename M>
void iter(T *address, size_t length, void (*random_function)(M)){
    for (size_t i = 0; i < length; i++) {
        T value = address[i];
        random_function(value);
    }
}

template<typename T>
void iter(T *address, size_t length, void (*random_function)(T)){
    for (size_t i = 0; i < length; i++) {
        T value = address[i];
        random_function(value);
    }
}

#endif