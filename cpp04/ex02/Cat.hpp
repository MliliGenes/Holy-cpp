#pragma once

#include "AnimalA.hpp"
#include "Brain.hpp"

class Cat : public AnimalA {
private:
    Brain *bigBrain;
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    virtual void makeSound() const;
};
