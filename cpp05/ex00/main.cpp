#include "Bureaucrat.hpp"

int main() {
    try {
        B dude("dude", 4);
        B lol = dude;
        std::cout << dude << std::endl;
        std::cout << lol << std::endl;
        dude.promote().promote().promote();
        std::cout << dude << std::endl;
    } catch ( std::exception& e ) {
        std::cerr << e.what() << std::endl;
    } 
}