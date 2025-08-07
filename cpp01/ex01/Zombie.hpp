# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

#define MEOW "BraiiiiiiinnnzzzZ..."
#define DEAD "OOooH NNOoo!!! Nooo bRaAiiiIIIiNZzzz..."

class Zombie {
        
    private :

        std::string _name;

    public :

        Zombie( void );
        ~Zombie( void );

        void announce( void );
        void _setName( std::string );

};

Zombie* zombieHorde( int N, std::string name );

# endif
