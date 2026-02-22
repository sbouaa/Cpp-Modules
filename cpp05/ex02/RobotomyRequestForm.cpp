#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string s) : AForm("RobotomyRequestForm", 72, 45), target(s) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& x) : AForm(x), target(x.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& x)
{
    if (&x != this)
    {
        AForm::operator=(x);
        target = x.target;
    }
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    Check(executor);
    std::cout<<"waaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
    if (std::rand() % 2)
        std::cout<<target<<" has been robotomized successfully\n";
    else
        std::cout<<target<<" robotomization failed\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {}