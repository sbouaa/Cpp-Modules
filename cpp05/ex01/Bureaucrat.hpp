#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
    public :
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& x);
        Bureaucrat &operator=(const Bureaucrat& x);
        ~Bureaucrat();
        std::string getName() const;
        int         getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
        class   GradeTooHighException : public std::exception
        {
            public :
                const char* what() const throw()
                {
                    return "Grade is too high";
                }
        };

        class   GradeTooLowException : public std::exception
        {
            public :
                const char* what() const throw()
                {
                    return "Grade is too low";
                }
        };
        void    signForm(Form &x);
};

std::ostream& operator <<(std::ostream &c, const Bureaucrat &x);

#endif