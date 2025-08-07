#include "Zombie.hpp"

Zombie::Zombie( void ) {

    _name = "";

} 

Zombie::~Zombie( void ) {

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

void Zombie::_setName ( std::string name ) {

    _name = name;

}
