#include "Contact.hpp"
#include "PhoneBook.hpp"

typedef struct contact
{
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
} contact;

contact create_contact() {
    contact c;

    std::cin >> c._firstName;
    std::cin >> c._lastName;
    std::cin >> c._nickname;
    std::cin >> c._phoneNumber;
    std::cin >> c._darkestSecret;

    return c;
}

int main()
{
    PhoneBook myPhoneBook;

    while (true)
    {
        std::cout << "hmm:" << std::endl;
        std::string cmd;
        std::cin >> cmd;
    }
}