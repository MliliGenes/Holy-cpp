#include "Contact.hpp"

Contact::Contact() {
    _firstName = "";
    _lastName = "";
    _nickname = "";
    _phoneNumber = "";
    _darkestSecret = "";
}

Contact::~Contact() {
    // meow
}

Contact::Contact(const Contact& other) {
    _firstName = other._firstName;
    _lastName = other._lastName;
    _nickname = other._nickname;
    _phoneNumber = other._phoneNumber;
    _darkestSecret = other._darkestSecret;
}

Contact& Contact::operator=(const Contact& other) {
    if (this == &other)
        return *this;
    
    _firstName = other._firstName;
    _lastName = other._lastName;
    _nickname = other._nickname;
    _phoneNumber = other._phoneNumber;
    _darkestSecret = other._darkestSecret;
    
    return *this;
}

void Contact::setContact(
    const std::string& firstName,
    const std::string& lastName,
    const std::string& nickname,
    const std::string& phoneNumber,
    const std::string& darkestSecret
) {
    _firstName = firstName;
    _lastName = lastName;
    _nickname = nickname;
    _phoneNumber = phoneNumber;
    _darkestSecret = darkestSecret;
}

void Contact::display() const {
std::cout << "    " << CYAN << "→ " << RESET << BOLD << "First Name: " << RESET 
              << _firstName << "\n";
    std::cout << "    " << CYAN << "→ " << RESET << BOLD << "Last Name: " << RESET 
              << _lastName << "\n";
    std::cout << "    " << CYAN << "→ " << RESET << BOLD << "Nickname: " << RESET 
              << _nickname << "\n";
    std::cout << "    " << CYAN << "→ " << RESET << BOLD << "Phone Number: " << RESET 
              << _phoneNumber << "\n";
    std::cout << "    " << CYAN << "→ " << RESET << BOLD << "Darkest Secret: " << RESET 
              << _darkestSecret << "\n";
}

std::string Contact::getFirstName(void) const {
    return _firstName;
}

std::string Contact::getLastName(void) const {
    return _lastName;
}

std::string Contact::getNickname(void) const {
    return _nickname;
}