# ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {

    private :

        std::string name;
        Weapon& _weapon;

    public :
        
        HumanA( std::string _name, Weapon& weapon ) : name( _name ), _weapon( weapon ) {}
        
        void attack( void );
        void setWeapon( Weapon& );

};

# endif
