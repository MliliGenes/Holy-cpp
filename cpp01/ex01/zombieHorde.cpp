#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    
    Zombie *horde = NULL;

    try {

        horde = new Zombie[N];
        
        for ( int i = 0; i < N; i ++ ) {
            horde[i]._setName( name );
        }

    } catch (const std::bad_alloc& e) {

        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return NULL;

    }
    
    return horde;

}
