#include "Form.hpp"

Form::Form(const std::string name, int gradeS, int gradeE) : name(name), 
sign(false), gradeSign(gradeS), gradeExecute(gradeE)
{
    if (gradeExecute < 1 || gradeSign < 1)
        throw Form::GradeTooHighException();
    else if (gradeExecute > 150 || gradeSign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& x) : name(x.name), sign(x.sign), gradeSign(x.gradeSign), gradeExecute(x.gradeExecute) {}

Form& Form::operator=(const Form& x)
{
    if (&x != this)
        sign = x.sign;
    return *this;
}

const std::string Form::getName() const
{
    return name;
}

int Form::getGradeExecute() const
{
    return gradeExecute;
}

int Form::getGradeSign() const
{
    return gradeSign;
}

std::ostream& operator<<(std::ostream& os, const Form& x)
{
    os << "Form " << x.getName()<< " | grade to sign: " << x.getGradeSign()
    << " | grade to execute: " << x.getGradeExecute();
    return os;
}

void    Form::beSigned(Bureaucrat &x)
{
    if (x.getGrade() > gradeSign)
        throw Form::GradeTooLowException();
    sign = true;
}

Form::~Form() {}

