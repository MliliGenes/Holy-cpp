#include "ClapTrap.hpp"

int main() {
    std::cout << "=== Bienvenue au test de ClapTrap! ===\n" << std::endl;

    std::cout << "--- Constructing robots ---" << std::endl;
    ClapTrap clap1("Baguette-Bot");
    ClapTrap clap2("Croissant-Crusher");

    std::cout << "\n--- Round 1: Attacks ---" << std::endl;
    clap1.attack("ze English");
    clap2.attack("ze Germans");

    std::cout << "\n--- Round 2: Taking damage ---" << std::endl;
    clap1.takeDamage(5);
    clap2.takeDamage(3);

    std::cout << "\n--- Round 3: Repairs ---" << std::endl;
    clap1.beRepaired(2);
    clap2.beRepaired(1);

    std::cout << "\n--- Round 4: Copy constructor ---" << std::endl;
    ClapTrap clap3(clap1);
    clap3.attack("ze surrender flag");

    std::cout << "\n--- Round 5: Assignment operator ---" << std::endl;
    clap3 = clap2;
    clap3.attack("ze butter thief");

    std::cout << "\n--- Round 6: Exhausting energy ---" << std::endl;
    for (int i = 0; i < 12; i++) {
        clap1.attack("ze endless enemy");
    }

    std::cout << "\n=== End of ClapTrap tests ===" << std::endl;
    return 0;
}
