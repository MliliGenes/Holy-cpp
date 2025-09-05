#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {
    type = "Cat";
    bigBrain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    bigBrain = new Brain(*other.bigBrain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *bigBrain = *other.bigBrain;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete bigBrain;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
