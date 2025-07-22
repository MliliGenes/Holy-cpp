#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
    
    public:
        Contact();
        Contact(const Contact& other);
        Contact& operator=(const Contact& other);
        ~Contact();

        void setContact(
            const std::string& firstName,
            const std::string& lastName,
            const std::string& nickname,
            const std::string& phoneNumber,
            const std::string& darkestSecret
        );

        void display() const;
};

#endif