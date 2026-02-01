#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), count(0) {}

void	PhoneBook::addContact()
{
	contacts[index].setContact();
	index = (index + 1) % 8;
	if (count < 8)
		count++;
}

void PhoneBook::searchContact()
{
    std::string in;
    if (count == 0)
    {
        std::cout << "No contacts available!\n";
        return;
    }
    printContacts();
    std::cout << "Enter the index (0 - " << count - 1 << ") to view details: ";
    std::getline(std::cin, in);
    if (std::cin.eof())
        (std::cout<<"\n    EOF!!!!!!   \n", exit(1));
    int i = in[0] - '0';
    if (i < 0 || i >= count || in.length() > 2)
    {
        std::cout << "Invalid index! Please enter a number between 0 and "<<count - 1<<std::endl;
        return;
    }
    contacts[i].printContact();
}

std::string format(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::printContacts()
{
    std::cout <<"|----------|----------|----------|----------|\n";
    std::cout <<"|     index| FirstName|  LastName|  NickName|\n";
    std::cout <<"|----------|----------|----------|----------|\n";
    for (int i = 0; i < count; i++)
    {
        std::cout << "|" << std::setw(10) << i
                  << "|" << format(contacts[i].getFirstName())
                  << "|" << format(contacts[i].getLastName())
                  << "|" << format(contacts[i].getNickName())
                  << "|\n";
    }
    std::cout <<"|----------|----------|----------|----------|\n";
}

