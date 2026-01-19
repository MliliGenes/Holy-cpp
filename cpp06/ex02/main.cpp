#include "Base.hpp"
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// void ll() {
//     system("leaks ex02");
// }

int main() {
    // atexit(ll);
    std::srand(std::time(NULL));

    std::cout << "=== Testing identify(Base* p) ===" << std::endl;
    
    // Test with multiple random generations
    for (int i = 0; i < 5; i++) {
        Base* obj = generate();
        std::cout << "Identified via pointer: ";
        identify(obj);
        std::cout << "Identified via reference: ";
        identify(*obj);
        delete obj;
        std::cout << std::endl;
    }
    
    // std::cout << "\n=== Testing with known types ===" << std::endl;
    
    // // Test with known types
    // Base* a = new A();
    // Base* b = new B();
    // Base* c = new C();
    
    // std::cout << "Object A:" << std::endl;
    // std::cout << "  Via pointer: ";
    // identify(a);
    // std::cout << "  Via reference: ";
    // identify(*a);
    
    // std::cout << "Object B:" << std::endl;
    // std::cout << "  Via pointer: ";
    // identify(b);
    // std::cout << "  Via reference: ";
    // identify(*b);
    
    // std::cout << "Object C:" << std::endl;
    // std::cout << "  Via pointer: ";
    // identify(c);
    // std::cout << "  Via reference: ";
    // identify(*c);
    
    // delete a;
    // delete b;
    // delete c;
    
    return 0;
}