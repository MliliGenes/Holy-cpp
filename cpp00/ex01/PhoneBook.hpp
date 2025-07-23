#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
    int _contactCount;
    int _nextIndex;
    
    public:
        Contact _contacts[8];
        PhoneBook();
        PhoneBook(const PhoneBook &other);
        PhoneBook &operator=(const PhoneBook &other);
        ~PhoneBook();

        // void addContact(const Contact &contact);
        // void searchContact() const;
        // void displayAllContacts() const;
};

#endif