#include "Zombie.hpp"

void Zombie::announce( void ) {

    std::cout << _name
        << ": " 
        << MEOW 
        << std::endl;

}

Zombie::~Zombie() {

    // meow
    std::cout << _name << std::endl;

}

Zombie *newZombie( std::string name ) {
    
    Zombie *_ana = NULL;

    try {

        _ana = new Zombie( name );

    }  catch (const std::bad_alloc& e) {

         std::cerr << "Allocation failed: " << e.what() << '\n';

    }
 
    return _ana;

}

void randomChump( std::string name ) {
    
    Zombie *zombie = newZombie( name );
    
    if ( zombie ) {

        zombie->announce();
        delete zombie;

    } else {

        std::cout << "Allocation failed"
            << std::endl;

    }
}






