#include <iostream>
#include "Point.hpp"  // includes Fixed + Point + pointInTriangle

int main(void) {

    // Fixed a;
    // Fixed const b(Fixed(5.05f) * Fixed(2));

    // std::cout << "Testing Fixed class:" << std::endl;
    // std::cout << a << std::endl;          // 0
    // std::cout << ++a << std::endl;        // 1
    // std::cout << a << std::endl;          // 1
    // std::cout << a++ << std::endl;        // 1 (before increment)
    // std::cout << a << std::endl;          // 2 (after increment)
    // std::cout << b << std::endl;          // 10.10 approx
    // std::cout << Fixed::max(a, b) << std::endl; // max(2, 10.10)

    std::cout << "\n---\n" << std::endl;

    // --- Test Point + Triangle inclusion ---
    Point A(0.0f, 0.0f);
    Point B(4.0f, 0.0f);
    Point C(2.0f, 4.0f);

    Point P_inside(2.0f, 2.0f);
    Point P_outside(5.0f, 2.0f);
    Point P_edge(2.0f, 0.0f); // lies on AB

    std::cout << "Testing pointInTriangle:" << std::endl;

    std::cout << "P_inside (2,2): "
              << (bsp(A, B, C, P_inside) ? "inside" : "outside")
              << std::endl;

    std::cout << "P_outside (5,2): "
              << (bsp(A, B, C, P_outside) ? "inside" : "outside")
              << std::endl;

    std::cout << "P_edge (2,0): "
              << (bsp(A, B, C, P_edge) ? "inside" : "outside")
              << std::endl;

    return 0;
}
