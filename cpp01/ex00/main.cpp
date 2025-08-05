#include "Zombie.hpp"

int main() {
    // Test 1: Using newZombie (heap allocation, manual delete)
    Zombie* z1 = newZombie("Zombo");
    if (z1) {
        z1->announce();
        delete z1; // free memory
    } else {
        std::cerr << "Failed to create zombie with newZombie\n";
    }

    std::cout << "--------------------------\n";

    // Test 2: Using randomChump (auto delete inside function)
    randomChump("Chumpy");

    std::cout << "--------------------------\n";

    // Test 3: Create multiple zombies
    Zombie* z2 = newZombie("Ghoulie");
    Zombie* z3 = newZombie("Skeletor");
    if (z2) z2->announce();
    if (z3) z3->announce();

    // Clean up
    delete z2;
    delete z3;

    return 0;
}

