#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string s) : AForm("ShrubberyCreationForm", 145, 137), target(s) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& x) : AForm(x) , target(x.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& x)
{
    if (&x != this)
    {
        AForm::operator=(x);
        target = x.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    Check(executor);
    std::string name = target + "_shrubbery";
    std::ofstream file(name.c_str());
    file << "     -    \n"<<"    --    \n"<<"    ---   \n"<<"   -----  \n"<<"  ------- \n"<<"  -------- \n"<<" ---------- \n";
    file<<"    ||    \n";
    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

