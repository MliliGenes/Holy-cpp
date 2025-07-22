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
}