#include "AnimalA.hpp"

AnimalA::AnimalA() : type("AnimalA") {
    std::cout << "AnimalA default constructor called" << std::endl;
}

AnimalA::AnimalA(const AnimalA& other) : type(other.type) {
    std::cout << "AnimalA copy constructor called" << std::endl;
}

AnimalA& AnimalA::operator=(const AnimalA& other) {
    std::cout << "AnimalA assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AnimalA::~AnimalA() {
    std::cout << "AnimalA destructor called" << std::endl;
}

void AnimalA::makeSound() const {
    std::cout << "* Some generic AnimalA sound *" << std::endl;
}

std::string AnimalA::getType() const {
    return type;
}