#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== Bienvenue à la grande démonstration des robots français! ===\n" << std::endl;

    ClapTrap clap("Petit-Pain");
    ScavTrap scav("Grand-Croissant");
    FragTrap frag("Pain-au-Chocolat");
    DiamondTrap diamond("Brioche-Royale");

    std::cout << "\n--- Round 1: Attaques ---" << std::endl;
    clap.attack("ze baguette thief");
    scav.attack("ze bakery staff");
    frag.attack("ze chocolate hoarder");
    diamond.attack("ze royal pâtisserie");

    std::cout << "\n--- Round 2: Taking ze damages ---" << std::endl;
    clap.takeDamage(5);
    scav.takeDamage(15);
    frag.takeDamage(20);
    diamond.takeDamage(30);

    std::cout << "\n--- Round 3: Self-repairs ---" << std::endl;
    clap.beRepaired(3);
    scav.beRepaired(10);
    frag.beRepaired(15);
    diamond.beRepaired(25);

    std::cout << "\n--- Round 4: Special abilities ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    diamond.whoAmI();
    diamond.getMembers();

    std::cout << "\n--- Round 5: Copy & Assignment ---" << std::endl;
    ClapTrap clapCopy = clap;
    ScavTrap scavCopy(scav);
    FragTrap fragCopy(frag);
    DiamondTrap diamondCopy(diamond);

    clapCopy.attack("ze fake butter");
    scavCopy.guardGate();
    fragCopy.highFivesGuys();
    diamondCopy.whoAmI();

    std::cout << "\n=== La démonstration est terminée! Vive les robots français! ===" << std::endl;
    return 0;
}
