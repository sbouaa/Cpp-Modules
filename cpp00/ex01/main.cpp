#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook book;
    while (1)
    {
        std::string str;
        std::cout << "Enter :: { ---------> ADD, SEARCH or EXIT <----------- }"<<std::endl;
        std::getline(std::cin, str);
        if (std::cin.eof())
            (std::cout<<"\n    EOF!!!!!!   \n", exit(1));
        if (str.empty())
            continue;
        if (str == "ADD")
            book.addContact();
        if (str == "SEARCH")
            book.searchContact();
        if (str == "EXIT")
            exit(1);
    }
    return 0;
}