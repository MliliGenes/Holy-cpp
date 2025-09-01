#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string _name) : ClapTrap(_name)={

    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "le fragtrap: " << _name << " just been born!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "le fragtrap: " << name << " just been aborted!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap " << other.name 
            << " has been cloned like ze best French wine recipe!" 
            << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << other.name 
            << " has been copied avec style et élégance!" 
            << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name 
            << " requests a *HIGH FIVE*! ✋ Allez mes amis, spread ze positivity!" 
            << std::endl;
}