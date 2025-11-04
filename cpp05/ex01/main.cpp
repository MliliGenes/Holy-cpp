#include "Bureaucrat.hpp"

int main() {
    try {
        B dude("dude", 4);
        std::cout << dude << std::endl;
        dude.promote(3);
        std::cout << dude << std::endl;
    } catch ( std::exception& e ) {
        std::cerr << e.what() << std::endl;
    } 
}