#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a(5,"qwe");
        a.decrementGrade();
        std::cout<<a;
        Bureaucrat b(149, "aaaa");
        std::cout<<b;
    }
    catch (std::exception &x)
    {
        std::cout<<x.what();
    }
    return 0;
}