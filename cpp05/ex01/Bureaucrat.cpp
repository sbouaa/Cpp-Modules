#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &x) : name(x.name), grade(x.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& x)
{
    if (&x != this)
        grade = x.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat() {}

int    Bureaucrat::getGrade() const
{
    return grade;
}

std::string Bureaucrat::getName() const
{
    return name;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream& operator <<(std::ostream &c, const Bureaucrat &x)
{
    c<<x.getName() << ", bureaucrat grade " << x.getGrade() << "\n";
    return c;
}

void    Bureaucrat::signForm(Form &x)
{
    try
    {
        x.beSigned(*this);
        std::cout<<name<<" signed "<<x.getName()<<std::endl;
    }
    catch(std::exception &y)
    {
        std::cout<<name<<" couldn't sign "<<x.getName()<<" because "<<y.what();
    }
}