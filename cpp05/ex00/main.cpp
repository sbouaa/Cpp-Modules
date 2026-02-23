#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a(1,"Bjarne");
        a.decrementGrade();
        std::cout<<a;
        Bureaucrat b(129, "dennis");
        std::cout<<b;
    }
    catch (std::exception &x)
    {
        std::cout<<x.what();
    }
    return 0;
}