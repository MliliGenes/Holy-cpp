#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define WHITE   "\033[37m"

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

        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickname(void) const;

        void setContact(
            const std::string& firstName,
            const std::string& lastName,
            const std::string& nickname,
            const std::string& phoneNumber,
            const std::string& darkestSecret
        );

        void displagety() const;
};

#endif