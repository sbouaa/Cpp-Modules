#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout<<"--------\n";
    try {
        sp.addNumber(42);
    }
    catch (Span::Add &x)
    {
        std::cout<<x.what();
    }
    std::cout<<"--------\n";
    Span a(5);
    try{
        a.shortestSpan();
    }
    catch (std::exception &x)
    {
        std::cout<<x.what();
    }
    a.addNumber(133);
    a.addNumber(144);
    std::cout<<a.shortestSpan()<<std::endl;
    std::cout<<a.longestSpan()<<std::endl;
    std::cout<<"--------\n";
    std::vector<int> b;
    for (int i = 0; i < 26; i++)
        b.push_back(i*7);
    Span c(30);
    c.addNumbers(b.begin(), b.end());
    std::cout<<c.shortestSpan()<<std::endl;
    std::cout<<c.longestSpan()<<std::endl;

    try {
        Span x(5);
        x.addNumbers(b.begin(), b.end());
    }
    catch (std::exception &x)
    {
        std::cout<<x.what();
    }

    Span big(10000);
    std::vector <int> bigs;
    bigs.reserve(10000);
    for (int i = 0; i < 10000; i++)
        bigs.push_back(i * 5);
    big.addNumbers(bigs.begin(), bigs.end());
    std::cout<<big.longestSpan()<<std::endl;
    std::cout<<big.shortestSpan()<<std::endl;
    return 0;
}