#ifndef Serializer_hpp
#define Serializer_hpp

#include "Data.hpp"
#include <stdint.h>

class Serializer {
private:
    Serializer();
    Serializer(const Serializer& other);
    const Serializer operator=(const Serializer& other);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif