#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer(Serializer const &rhs);
        Serializer& operator=(Serializer const &rhs);
        Serializer();
        virtual ~Serializer() = 0;
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif