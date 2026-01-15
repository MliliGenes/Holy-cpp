#pragma once

#include <stdint.h>
#include "Data.hpp"

class Serializer {
    private:
        // Private constructors to prevent instantiation
        Serializer();
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer& operator=(const Serializer &other);
    
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};