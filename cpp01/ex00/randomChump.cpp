#include "Zombie.hpp"

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
