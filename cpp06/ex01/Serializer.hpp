#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    std::string s;
    int a;
};

class Serializer
{
    private :
        Serializer();
        Serializer(const Serializer& x);
        Serializer& operator=(const Serializer& x);
        ~Serializer();
    public :
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif