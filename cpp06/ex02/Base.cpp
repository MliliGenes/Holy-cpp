#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) {    
    int random = std::rand() % 3;
    // std::cout << random << std::endl;
    switch (random) {
        case 0:
            std::cout << "[Generated A]" << std::endl;
            return new A();
        case 1:
            std::cout << "[Generated B]" << std::endl;
            return new B();
        case 2:
            std::cout << "[Generated C]" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    // Try to dynamic_cast to each type
    // dynamic_cast returns NULL if the cast fails
    
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    // With references, we can't use pointers!
    // dynamic_cast with references throws an exception if it fails
    // So we use try-catch to identify the type
    
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {
        // Not type A, continue checking
    }
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {
        // Not type B, continue checking
    }
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {
        // Not type C either
        std::cout << "Unknown type" << std::endl;
    }
}