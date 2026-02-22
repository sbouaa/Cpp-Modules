#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private :
        const   std::string name;
        bool    sign;
        const int   gradeSign;
        const int   gradeExecute;
    public :
        Form(const std::string name, int gradeS, int gradeE);
        Form(const Form &x);
        Form& operator=(const Form& x);
        ~Form();
    class GradeTooHighException : public std::exception
    {
        public :
            const char *what() const throw()
            {
                return "Grade is too High\n";
            }
    };

    class GradeTooLowException : public std::exception
    {
        public :
            const char* what() const throw()
            {
                return "Grade is too Low\n";
            }
    };
    const std::string getName() const;
    int     getGradeSign() const;
    int     getGradeExecute() const;
    void    beSigned(Bureaucrat &x);
};

std::ostream& operator<<(std::ostream& os, const Form& x);

#endif