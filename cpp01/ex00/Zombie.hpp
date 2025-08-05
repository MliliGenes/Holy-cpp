# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstddef>

#define MEOW "BraiiiiiiinnnzzzZ..."
#define DEAD ""

class Zombie {
        
    private :

        std::string _name;

    public :

        Zombie( std::string name ) : _name( name ) {}
        ~Zombie( void );
        void announce( void );

};



Zombie *newZombie( std::string name );

void randomChump( std::string name );



# endif
