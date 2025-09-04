#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Creating objects ===" << std::endl;
    
    Animal* genericAnimal = new Animal();
    Animal* dogAsAnimal = new Dog();
    Animal* catAsAnimal = new Cat();
    
    Dog* directDog = new Dog();
    Cat* directCat = new Cat();

    std::cout << "\n=== Testing types ===" << std::endl;
    std::cout << "Generic animal type: " << genericAnimal->getType() << std::endl;
    std::cout << "Dog as Animal type: " << dogAsAnimal->getType() << std::endl;
    std::cout << "Cat as Animal type: " << catAsAnimal->getType() << std::endl;
    std::cout << "Direct Dog type: " << directDog->getType() << std::endl;
    std::cout << "Direct Cat type: " << directCat->getType() << std::endl;

    std::cout << "\n=== Testing polymorphic makeSound() ===" << std::endl;
    std::cout << "Generic animal sound: ";
    genericAnimal->makeSound();
    
    std::cout << "Dog as Animal sound: ";
    dogAsAnimal->makeSound();
    
    std::cout << "Cat as Animal sound: ";
    catAsAnimal->makeSound();
    
    std::cout << "Direct Dog sound: ";
    directDog->makeSound();
    
    std::cout << "Direct Cat sound: ";
    directCat->makeSound();

    std::cout << "\n=== Testing copy constructor ===" << std::endl;
    Dog copyDog(*directDog);
    Cat copyCat(*directCat);
    
    std::cout << "Copy dog type: " << copyDog.getType() << std::endl;
    std::cout << "Copy cat type: " << copyCat.getType() << std::endl;
    
    std::cout << "Copy dog sound: ";
    copyDog.makeSound();
    
    std::cout << "Copy cat sound: ";
    copyCat.makeSound();

    std::cout << "\n=== Testing assignment operator ===" << std::endl;
    Dog assignedDog;
    Cat assignedCat;
    
    assignedDog = *directDog;
    assignedCat = *directCat;
    
    std::cout << "Assigned dog type: " << assignedDog.getType() << std::endl;
    std::cout << "Assigned cat type: " << assignedCat.getType() << std::endl;
    
    std::cout << "Assigned dog sound: ";
    assignedDog.makeSound();
    
    std::cout << "Assigned cat sound: ";
    assignedCat.makeSound();

    std::cout << "\n=== Testing array of Animals ===" << std::endl;
    Animal* animals[4];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Dog();
    
    for (int i = 0; i < 4; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }

    std::cout << "\n=== Cleaning up ===" << std::endl;
    delete genericAnimal;
    delete dogAsAnimal;
    delete catAsAnimal;
    delete directDog;
    delete directCat;
    
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }

    return 0;
}