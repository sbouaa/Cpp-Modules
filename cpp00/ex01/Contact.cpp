#include "PhoneBook.hpp"

std::string Contact::getFirstName()
{
    return firstName;
}

std::string Contact::getLastName()
{
    return lastName;
}

std::string Contact::getNickName()
{
    return nickName;
}

int check(std::string str, int flag)
{
    char c;
    if (flag == 1)
    {
        for (int i = 0; i < (int)str.size(); i++)
        {
            c = str[i];
            if (!isprint(c) || !isalpha(c))
                return 1;
        }
    }
    if (flag == 2)
    {
        for (int i = 0; i < (int)str.size(); i++)
        {
            c = str[i];
            if (!isdigit(c))
                return 1;
        }
    }
    return 0;
}

void    Contact::setContact()
{
    while (1)
    {
        std::string str;
        std::cout<<"Enter First Name :: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            (std::cout<<"\n    EOF!!!!!!   \n", exit(1));
        if (str.empty() || check(str, 1))
            continue;
        firstName = str;
        std::cout<<"Enter Last Name :: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            (std::cout<<"\n    EOF!!!!!!   \n", exit(1));
        if (str.empty() || check(str, 1))
            continue;
        lastName = str;
        std::cout<<"Enter NickName :: ";
        std::getline(std::cin, str);        
        if (std::cin.eof())
            (std::cout<<"\n    EOF!!!!!!   \n", exit(1));
        if (str.empty() || check(str, 1))
            continue;
        nickName = str;
        std::cout<<"Enter Phone Number :: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            (std::cout<<"\n    EOF!!!!!!   \n", exit(1));
        if (str.empty() || check(str, 2))
            continue;
        phoneNumber = str;
        std::cout<<"Enter your darkest secret :: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
            (std::cout<<"\n    EOF!!!!!!   \n", exit(1));
        if (str.empty() || check(str, 1))
            continue;
        darkestSecret = str;
        return ;
    }
    return ;
}

void Contact::printContact()
{
    std::cout << "First Name :: " << firstName << std::endl;
    std::cout << "Last Name :: " << lastName << std::endl;
    std::cout << "Nick Name :: " << nickName << std::endl;
    std::cout << "Phone Number :: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret :: " << darkestSecret << std::endl;
}

