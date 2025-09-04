#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Correct Classes (with virtual) ===" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog through Animal*: ";
    dog->makeSound(); // ✅ runtime polymorphism → Woof!

    std::cout << "Cat through Animal*: ";
    cat->makeSound(); // ✅ runtime polymorphism → Meow!

    delete dog;
    delete cat;

    std::cout << "\n=== Wrong Classes (no virtual) ===" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongCat through WrongAnimal*: ";
    wrongCat->makeSound(); // ⚠ compile-time binding → WrongAnimal sound

    delete wrongCat;

    return 0;
}
