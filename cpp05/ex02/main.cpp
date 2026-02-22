#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat b("Alice", 10);
        RobotomyRequestForm f("Mick");
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<"------------------------------\n";
    try {
        Bureaucrat a("slack", 77);
        ShrubberyCreationForm e("extryo");
        a.signForm(e);
        a.executeForm(e);
    }
    catch (std::exception &x) {
        std::cout<<x.what()<<std::endl;
    }
    std::cout<<"------------------------------\n";
    try 
    {
        Bureaucrat c("sovyanos", 148);
        PresidentialPardonForm d("bghawt");
        c.decrementGrade();
        std::cout<<c;
        c.signForm(d);
        c.executeForm(d);
    }
    catch (std::exception &q)
    {
        std::cout<<q.what()<<std::endl;
    }
    return 0;
}