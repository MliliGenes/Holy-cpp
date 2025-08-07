#include "HumanA.hpp"

void HumanA::attack( void ) {

    std::cout << name
        << " attacks with their "
        << _weapon.getType()
        << std::endl;

}

void HumanA::setWeapon( Weapon& weapon ) {
    
    _weapon = weapon;

}
