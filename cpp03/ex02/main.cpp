#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== Bienvenue à la bataille ultime des robots français! ===\n" << std::endl;

    ClapTrap clap("Petit-Pain");
    ScavTrap scav("Grand-Croissant");
    FragTrap frag("Pain-au-Chocolat");

    std::cout << "\n--- Round 1: Attacks ---" << std::endl;
    clap.attack("ze baguette thief");
    scav.attack("ze bakery staff");
    frag.attack("ze chocolate hoarder");

    std::cout << "\n--- Round 2: Taking damage ---" << std::endl;
    clap.takeDamage(7);
    scav.takeDamage(25);
    frag.takeDamage(15);

    std::cout << "\n--- Round 3: Repairs ---" << std::endl;
    clap.beRepaired(5);
    scav.beRepaired(20);
    frag.beRepaired(30);

    std::cout << "\n--- Round 4: Special abilities ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();

    std::cout << "\n--- Round 5: Copy & Assignment ---" << std::endl;
    ClapTrap clapCopy = clap;
    ScavTrap scavCopy(scav);
    FragTrap fragCopy = frag;

    clapCopy.attack("ze fake butter");
    scavCopy.attack("ze impostor croissant maker");
    fragCopy.highFivesGuys();

    std::cout << "\n=== La bataille est terminée! Vive les robots français! ===" << std::endl;
    return 0;
}
