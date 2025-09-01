#pragma once

#include <iostream>
#include <string>

class ClapTrap
{

protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    ClapTrap(const std::string _name);
    ~ClapTrap(void);

    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};
