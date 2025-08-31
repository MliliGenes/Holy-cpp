#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Bienvenue à la grande bataille des robots français! ===\n" << std::endl;

    ClapTrap clap("Petit-Pain");
    ScavTrap scav("Grand-Croissant");

    std::cout << "\n--- Round 1: Attaque de base ---" << std::endl;
    clap.attack("ze unsuspecting baguette thief");
    scav.attack("ze entire bakery");

    std::cout << "\n--- Round 2: Ouch, damage incoming ---" << std::endl;
    clap.takeDamage(7);
    scav.takeDamage(30);

    std::cout << "\n--- Round 3: Repairs avec amour ---" << std::endl;
    clap.beRepaired(5);
    scav.beRepaired(20);

    std::cout << "\n--- Round 4: Special French powers ---" << std::endl;
    scav.guardGate();

    std::cout << "\n--- Round 5: Copy & Assignment ---" << std::endl;
    ScavTrap scavCopy(scav);
    scavCopy.attack("ze impostor croissant maker");

    ClapTrap clapCopy = clap;
    clapCopy.attack("ze fake butter");

    std::cout << "\n=== La bataille est terminée! ===" << std::endl;
    return 0;
}
