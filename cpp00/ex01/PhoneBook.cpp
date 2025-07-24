#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    _contactCount = 0;
    _nextIndex = 0;
}

PhoneBook::~PhoneBook() {
    // big meow
}

PhoneBook::PhoneBook(const PhoneBook& other) {
    _contactCount = other._contactCount;
    _nextIndex = other._nextIndex;

    for (int i = 0; i < 8; i++)
        _contacts[i] = other._contacts[i];
}

PhoneBook& PhoneBook::operator=(const PhoneBook &other) {
    if (this == &other)
        return *this;

    _contactCount = other._contactCount;
    _nextIndex = other._nextIndex;
    
    for (int i = 0; i < 8; i++)
        _contacts[i] = other._contacts[i];

    return *this;
}

void PhoneBook::addContact(const Contact &contact) {
    int index = _nextIndex % 8;
    _contacts[index] = contact;

    _nextIndex ++;

    if (_contactCount < 8)
        _contactCount ++;
}

