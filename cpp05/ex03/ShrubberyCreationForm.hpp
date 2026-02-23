#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private :
        std::string target;
    public : 
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string s);
        ShrubberyCreationForm(const ShrubberyCreationForm& x);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& x);
        ~ShrubberyCreationForm();
        void  execute(Bureaucrat const &executor) const;
};

#endif