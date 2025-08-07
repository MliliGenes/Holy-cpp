#include "Zombie.hpp"

int main( int ac, char **av ) {
       
    int n = 5;
    Zombie *horde = zombieHorde( n, ac > 1 ? av[1] : "saad" );

    if ( horde ) {

        for (int i = 0; i < n; i++ ) {

            horde[i].announce();

        }

        delete[] horde;

    } else {

        std::cerr << "Failed to create array of zombies\n";
        return 1;

    }

    return 0;
}

