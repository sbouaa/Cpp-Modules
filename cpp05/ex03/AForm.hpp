#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private :
        const   std::string name;
        bool    sign;
        const int   gradeSign;
        const int   gradeExecute;
    public :
        AForm(const std::string name, int gradeS, int gradeE);
        AForm(const AForm &x);
        AForm& operator=(const AForm& x);
        virtual ~AForm();
        const std::string getName() const;
        int     getGradeSign() const;
        int     getGradeExecute() const;
        void    beSigned(Bureaucrat &x);
        virtual void  execute(Bureaucrat const &executor) const = 0;
        void    Check(Bureaucrat const &x) const;
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
    class NotSignedException : public std::exception
    {
        public :
            const char *what() const throw()
            {
                return "The form is not signed";
            }
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& x);

#endif