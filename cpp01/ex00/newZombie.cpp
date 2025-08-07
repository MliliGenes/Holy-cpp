#include "Zombie.hpp"

Zombie *newZombie( std::string name ) {

    Zombie *_ana = NULL;

    try {

        _ana = new Zombie( name );

    }  catch (const std::bad_alloc& e) {

         std::cerr << "Allocation failed: " << e.what() << '\n';

    }

    return _ana;

}
