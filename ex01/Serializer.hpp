#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "data.hpp"
#include <stdint.h>

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private:
    Serializer();
    Serializer(Serializer &Other);
    Serializer& operator=(Serializer &Other);
    ~Serializer();
};
#endif