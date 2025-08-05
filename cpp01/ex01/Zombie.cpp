#include "Zombie.hpp"

Zombie::~Zombie() {

    // meow
    std::cout << _name 
        << ": "
        << DEAD
        << std::endl;

}

void Zombie::announce( void ) {

    std::cout << _name
        << ": " 
        << MEOW 
        << std::endl;

}

