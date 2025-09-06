#pragma once

#include "AnimalA.hpp"
#include "Brain.hpp"

class Dog : public AnimalA {
private:
    Brain *bigBrain;
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    virtual void makeSound() const;
};