#include "ClapTrap.hpp"

int main() {
    std::cout << "Bringing ClapTraps into this cruel world..." << std::endl;
    ClapTrap robot1("Baguette-Bot");
    ClapTrap robot2("Croissant-Crusher");
    
    std::cout << "\nTime for some French warfare..." << std::endl;
    robot1.attack("ze English");
    robot2.attack("ze Germans");
    
    std::cout << "\nOh non! Zey are getting hurt..." << std::endl;
    robot1.takeDamage(5);
    robot2.takeDamage(3);
    
    std::cout << "\nTime for some French engineering..." << std::endl;
    robot1.beRepaired(2);
    robot2.beRepaired(1);
    
    std::cout << "\nCloning ze French robot..." << std::endl;
    ClapTrap robot3(robot1);
    robot3.attack("ze surrender flag");
    
    std::cout << "\nC'est fini! Time to abort ze mission..." << std::endl;
    return 0;
}