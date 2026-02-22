#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& x) { (void)x; }

Intern& Intern::operator=(const Intern& x)
{
    (void)x;
    return *this;
}

static AForm* makeShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm* makePardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string Form, std::string target)
{
    std::string s[3] = {"Shrubbery creation", "Robotomy request", "President pardon"};
    AForm* (*arr[3])(std::string) = {makeShrubbery, makeRobotomy, makePardon};
    for (int i = 0; i < 3; i++)
    {
        if (Form == s[i])
        {
            std::cout<<"Intern creates "<<Form<<std::endl;
            return arr[i](target);
        }
    }
    std::cout<<"Form "<<Form<<"does not exist\n";
    return NULL;
}

Intern::~Intern() {}