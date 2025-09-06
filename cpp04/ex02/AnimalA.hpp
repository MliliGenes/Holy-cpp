#pragma once

#include <string>
#include <iostream>

class AnimalA
{
protected:
    std::string type;

public:
    AnimalA();
    AnimalA(const AnimalA &other);
    AnimalA &operator=(const AnimalA &other);
    virtual ~AnimalA() = 0;

    virtual void makeSound() const = 0;
    std::string getType() const;
};