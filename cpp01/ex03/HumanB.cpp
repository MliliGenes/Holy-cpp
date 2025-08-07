#include "HumanB.hpp"

void HumanB::attack( void ) {

    std::cout << name
        << " attacks with their "
        << _weapon->getType()
        << std::endl;

}

void HumanB::setWeapon( Weapon& weapon ) {
    
    _weapon = &weapon;

}
