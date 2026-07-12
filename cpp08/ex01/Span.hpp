#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span 
{
    private :
        unsigned int N;
        std::vector<int> vec;
    public :
        Span();
        Span(unsigned int n);
        Span(const Span &x);
        Span &operator=(const Span &x);
        ~Span();
        void    addNumber(int x);
        int     shortestSpan();
        int     longestSpan();

        template <typename it>
        void addNumbers(it begin, it end)
        {
            int dst = std::distance(begin, end);
            if (dst < 0 || vec.size() +  static_cast<unsigned int>(dst) > N)
                throw Add();
            vec.insert(vec.end(), begin, end);
        }

        class Add : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return "can't add the Number!!!\n";
                }
        };
        class NoSpan : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return "can't Find Span!!!\n";
                }
        };

};

#endif