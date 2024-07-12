#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <exception>

template<typename T>
class Array{
public:
    Array();
    ~Array();
    Array(const Array &other);
    Array<T>& operator=(const Array &other);

    T& operator[](size_t i);
    Array(size_t n);
    size_t size() const;

    class oor;

private:
    T*              _array;
    size_t    _arraySize;
};

template<typename T>
class Array<T>::oor : public std::exception{
public:
    const char * what() const throw() {
        return "Index out of range";
    }
};

#include "Array.tpp"

#endif