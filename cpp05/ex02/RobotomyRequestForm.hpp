#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
    private :
        std::string target;
    public :
        RobotomyRequestForm(std::string &s);
        RobotomyRequestForm(const RobotomyRequestForm& x);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& x);
        void    execute(Bureaucrat const &executor) const;
        ~RobotomyRequestForm();
};

#endif