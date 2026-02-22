#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeS, int gradeE) : name(name), 
sign(false), gradeSign(gradeS), gradeExecute(gradeE)
{
    if (gradeExecute < 1 || gradeSign < 1)
        throw AForm::GradeTooHighException();
    else if (gradeExecute > 150 || gradeSign > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& x) : name(x.name), sign(x.sign), gradeSign(x.gradeSign), gradeExecute(x.gradeExecute) {}

AForm& AForm::operator=(const AForm& x)
{
    if (&x != this)
        sign = x.sign;
    return *this;
}

const std::string AForm::getName() const
{
    return name;
}

int AForm::getGradeExecute() const
{
    return gradeExecute;
}

int AForm::getGradeSign() const
{
    return gradeSign;
}

std::ostream& operator<<(std::ostream& os, const AForm& x)
{
    os << "AForm " << x.getName()<< " | grade to sign: " << x.getGradeSign()
    << " | grade to execute: " << x.getGradeExecute();
    return os;
}

void    AForm::beSigned(Bureaucrat &x)
{
    if (x.getGrade() > gradeSign)
        throw AForm::GradeTooLowException();
    sign = true;
}

void    AForm::Check(Bureaucrat const &x) const
{
    if (!sign)
        throw AForm::NotSignedException();
    if (x.getGrade() > gradeExecute)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

