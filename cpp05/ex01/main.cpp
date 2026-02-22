#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
        Bureaucrat b("Carol", 40);
        Form f("ExactForm", 0, 25);
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &w)
    {
        std::cout<<w.what();
    }
    return 0;
}