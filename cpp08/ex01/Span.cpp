#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n)
{}

Span::Span(const Span &x)
{
    *this = x;
}

Span& Span::operator=(const Span &x)
{
    if (this != &x)
    {
        if (vec.size() > 0)
            vec.clear();
        for (size_t i = 0; i < x.vec.size(); i++)
            vec.push_back(x.vec[i]);
        N = x.N;
    }
    return *this;
}

void    Span::addNumber(int x)
{
    if (N == vec.size())
        throw Add();
    vec.push_back(x);
}

int Span::shortestSpan()
{
    if (vec.size() <= 1)
        throw NoSpan();
    std::vector <int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    int a = tmp[1] - tmp[0];
    for (size_t i = 0; i < tmp.size() - 1; i++)
    {
        int b = tmp[i + 1] - tmp[i];
        if (b < a)
            a = b;
    }
    return a;
}

int Span::longestSpan()
{
    if (vec.size() <= 1)
        throw NoSpan();
    std::vector <int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    int a = tmp.back() - tmp[0];
    return a;
}

Span::~Span() {}