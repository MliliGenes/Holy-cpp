# ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {

    private :

        std::string name;
        Weapon* _weapon;

    public :
        
        HumanB( std::string _name ) : name( _name ), _weapon(NULL) {}
        
        void attack( void );
        void setWeapon( Weapon& );

};

# endif
