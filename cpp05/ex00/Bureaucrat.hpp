#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
    public :
        Bureaucrat();
        Bureaucrat(int grade, std::string name);
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
};

std::ostream& operator <<(std::ostream &c, const Bureaucrat &x);

#endif