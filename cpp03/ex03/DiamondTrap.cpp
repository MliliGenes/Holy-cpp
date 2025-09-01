#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string _name) : ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name) {
    // clap = name = suf -> Scav ->
                        // -> Frag
    // name = _name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "le DiamondTrap: " << _name << " just been born!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "le DiamondTrap: " << name << " just been aborted!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other) {
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