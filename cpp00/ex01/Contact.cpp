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
    std::cout << "First Name: "      << _firstName      << std::endl;
    std::cout << "Last Name: "       << _lastName       << std::endl;
    std::cout << "Nickname: "        << _nickname       << std::endl;
    std::cout << "Phone Number: "    << _phoneNumber    << std::endl;
    std::cout << "Darkest Secret: "  << _darkestSecret  << std::endl;
}
