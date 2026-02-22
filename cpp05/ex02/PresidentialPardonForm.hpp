#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
    private :
        std::string target;
    public :
        PresidentialPardonForm(std::string &s);
        PresidentialPardonForm(const PresidentialPardonForm &x);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& x);
        void    execute(Bureaucrat const &executor) const;
        ~PresidentialPardonForm();
};

#endif