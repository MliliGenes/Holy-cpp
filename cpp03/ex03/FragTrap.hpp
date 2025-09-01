#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

    public :
        FragTrap( const std::string _name );
        ~FragTrap( void );
        FragTrap( const FragTrap &other );
        FragTrap &operator=( const FragTrap &other );

        void highFivesGuys( void );

};