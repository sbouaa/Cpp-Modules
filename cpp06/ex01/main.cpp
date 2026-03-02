#include "Serializer.hpp"

int main(void)
{
    Data data;
    data.a  = 42;
    data.s = "hello";
    uintptr_t x = Serializer::serialize(&data);
    Data *p = Serializer::deserialize(x);
    if (&data == p)
        std::cout<<"Nice\n";
    std::cout<<p->a<<" | "<<data.a<<std::endl;
    std::cout<<p->s<<" | "<<data.s<<std::endl;
    int w = 1337;
    float *f = reinterpret_cast<float *>(&w);
    *f = 14.78f;
    std::cout<<w<<std::endl;
    return 0;
}