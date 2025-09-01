#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap  {

    public :
        DiamondTrap( const std::string _name );
        ~DiamondTrap( void );
        DiamondTrap( const DiamondTrap &other );
        DiamondTrap &operator=( const DiamondTrap &other );
        
        void attack( const std::string &target);
        void whoAmI( void ) const;
        void getMembers( void ) const;
};