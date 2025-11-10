#include "Bureaucrat.hpp"

int main(void) {
    try {
        B boutaina("boutaina", 5);
        std::cout << boutaina << std::endl;

        B ikram("ikram", 1);
        std::cout << ikram << std::endl;

        boutaina.demote().demote();
        std::cout << boutaina << std::endl;

        ikram.promote();
        std::cout << ikram << std::endl;
    } catch ( std::exception& e ) {
        std::cerr << e.what() << std::endl;
    } 
}