#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private :
        std::string target;
    public :
        RobotomyRequestForm(std::string s);
        RobotomyRequestForm(const RobotomyRequestForm& x);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& x);
        void    execute(Bureaucrat const &executor) const;
        ~RobotomyRequestForm();
};

#endif