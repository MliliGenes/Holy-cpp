#include "whatever.hpp"
#include <iostream>

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    float a = 2;
    float b = 3;

    std::cout << "[default] " << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "[swapped] " << "a = " << a << ", b = " << b << std::endl;

    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "123";
    std::string d = "1234";

    std::cout << "[default] " << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "[swapped] " << "c = " << c << ", d = " << d << std::endl;

    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

}