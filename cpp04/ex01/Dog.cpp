#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    bigBrain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    bigBrain = new Brain(*other.bigBrain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete bigBrain;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
