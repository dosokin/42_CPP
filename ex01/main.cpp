#include "Serializer.hpp"
#include "data.hpp"
#include <iostream>

int main(){
    Data *dataPtr = new Data;
    dataPtr->data1 = 5;
    dataPtr->data2 = 999;
    dataPtr->data3 = 42;
    uintptr_t raw;
    Data *anotherDataPtr = NULL;

    std::cout << dataPtr << std::endl;
    raw = Serializer::serialize(dataPtr);
    anotherDataPtr = Serializer::deserialize(raw);
    std::cout << anotherDataPtr << std::endl;
    delete dataPtr;
    return (1);
}