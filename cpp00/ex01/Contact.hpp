#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
    private:
        std::string  firstName;
        std::string  lastName;
        std::string  nickName;
        std::string  phoneNumber;
        std::string  darkestSecret;
    public:
        void setContact();
        void printContact();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
};

#endif