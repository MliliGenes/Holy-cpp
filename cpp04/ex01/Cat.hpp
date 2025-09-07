#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain *bigBrain;
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    virtual void makeSound() const;
};
