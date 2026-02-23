#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string s) : AForm("PresidentialPardonForm", 25, 5), target(s) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& x) : AForm(x), target(x.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& x)
{
    if (&x != this)
    {
        AForm::operator=(x);
        target = x.target;
    }
    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    Check(executor);
    std::cout<<target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
