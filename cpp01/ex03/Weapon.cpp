#include "Weapon.hpp" 
 
void Weapon::setType( std::string _type ) {

    // wtf would happend if the _type is null ???
    type = _type; 
   
}

std::string Weapon::getType( void ) const {

    // and what the fuck would happen if the type is still not defined ???
    return type;

}
