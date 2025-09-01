#include "ScavTrap.hpp"

ScavTrap::ScavTrap( const std::string _name ) : ClapTrap(_name) {

    // hitPoints = 100;
    energyPoints = 50;
    // attackDamage = 20;
    std::cout << "le scavtrap: " << name << " just been born!" << std::endl;

}

ScavTrap::~ScavTrap( void ) {

    std::cout << "le scavtrap: " << name << " just been aborted!" << std::endl;

}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "Sacré ScavTrap: " << other.name << " has been duplicated like a French croissant recipe!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "Sacré ScavTrap: " << other.name << " has been copied avec amour!" << std::endl;
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gatekeeper Mode! Nobody passes sans ze proper baguette!" << std::endl;
}

unsigned int ScavTrap::getEnergyPoints( void ) const {
    return energyPoints;
}