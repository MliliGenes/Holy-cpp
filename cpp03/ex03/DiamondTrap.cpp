#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string _name) : ClapTrap(_name),
    ScavTrap(_name), FragTrap(_name) {
    // hitPoints = getHitPoints();
    // energyPoints = getEnergyPoints();
    // attackDamage = getAttackDamage();
    std::cout << "le DiamondTrap: " << _name << " just been born!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "le DiamondTrap: " << name << " just been aborted!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
    ScavTrap(other), FragTrap(other) {
    std::cout << "DiamondTrap " << other.name 
            << " has been cloned like ze best French wine recipe!" 
            << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "DiamondTrap " << other.name 
            << " has been copied avec style et élégance!" 
            << std::endl;
    return *this;
}

void DiamondTrap::attack( const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void ) const {
    std::cout << "je mapil: " << this->name << ", mon grandpere est: " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::getMembers() const {
    std::cout << "hit: " << hitPoints << "\nenergy: " << energyPoints
            << "\nattack: " << attackDamage << std::endl;
}