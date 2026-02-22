#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat b("Alice", 55);
        ShrubberyCreationForm f("home");
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}