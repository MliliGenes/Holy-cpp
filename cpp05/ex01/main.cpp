#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        F wati9a("wati9a", 3, 1);
        B dude("dude", 4);
        dude.signForm(wati9a);
    } catch ( std::exception& e ) {
        std::cerr << e.what() << std::endl;
    } 
}