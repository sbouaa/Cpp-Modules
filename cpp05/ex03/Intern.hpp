#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
    public :
        Intern();
        Intern(const Intern& x);
        Intern& operator=(const Intern& x);
        AForm* makeForm(std::string Form, std::string target);
        ~Intern();
};

#endif