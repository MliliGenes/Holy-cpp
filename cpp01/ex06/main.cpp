#include "Harl.hpp"

int main() {
    Harl harl;

    // Test each level individually
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    // Test an unknown level
    harl.complain("RANDOM");

    return 0;
}
