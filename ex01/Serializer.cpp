#include <stdint.h>
#include "Serializer.hpp"
#include "data.hpp"

uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t  rew;
    uintptr_t& raw = rew;

    raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data* Serializer::deserialize(uintptr_t raw){
    Data *ptr;

    ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}

Serializer::Serializer(){}

Serializer::Serializer(Serializer &Other){
    (void)Other;
}

Serializer& Serializer::operator=(Serializer &Other){
    return Other;
}

Serializer::~Serializer(){}