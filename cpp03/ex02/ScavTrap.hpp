#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    public :
        ScavTrap(const std::string _name);
        ~ScavTrap();
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);

        void guardGate( void );

};