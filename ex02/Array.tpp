#include <cstdlib>

template<typename T>
Array<T>::Array() : _arraySize(0){
    _array = new T[0];
}

template<typename T>
Array<T>::Array(const size_t n) : _arraySize(n) {
    this->_array = new T[n];
    for (size_t i = 0; i < n; i++)
        this->_array[i] = T();
}

template<typename T>
Array<T>::~Array(){ delete []this->_array;}

template<typename T>
Array<T>::Array(const Array &other){
    size_t size = other.size();
    this->_arraySize = size;
    this->_array = new T[size];
    for (size_t i = 0; i < size; i++)
        this->_array.at(i) = other[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array &other){
    delete _array;
    size_t size = other.size();
    this->_arraySize = size;
    this->_array = new T[size];
    for (size_t i = 0; i < size; i++)
        this->_array.at(i) = other[i];
    return (*this);
}

template<typename T>
T& Array<T>::operator[](size_t i){
    if (i >= this->_arraySize)
        throw Array<T>::oor();
    return this->_array[i];
}

template<typename T>
size_t Array<T>::size() const
{
    return this->_arraySize;
}

