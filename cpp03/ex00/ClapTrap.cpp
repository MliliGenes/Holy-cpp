#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string _name) : name(_name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "le claptrap: " << _name << " just been born!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "le claptrap: " << name << " just been aborted!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this == &other)
        return *this;

    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;

    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (hitPoints > 0 && energyPoints > 0) {
        energyPoints--;
        std::cout << "ClapTrap " << name << " surrenders... wait non! Attacks " << target 
                  << " with " << attackDamage << " points of oui-damage!" << std::endl;
    } else
        std::cout << "ClapTrap " << name << " cannot attack! Too busy eating baguettes!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    hitPoints = (amount >= hitPoints) ? 0 : hitPoints - amount;
    std::cout << "Sacré bleu! ClapTrap " << name << " takes " << amount 
              << " points of damage! Très painful!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints > 0 && energyPoints > 0) {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " repairs itself with ze power of " 
                  << amount << " French engineering! Magnifique!" << std::endl;
    } else
        std::cout << "ClapTrap " << name << " cannot repair! Must find ze croissant first!" << std::endl;
}


