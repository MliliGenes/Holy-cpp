#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal(); // Note: NOT virtual - this is the key difference

    void makeSound() const; // Note: NOT virtual - compile-time binding
    std::string getType() const;
};
