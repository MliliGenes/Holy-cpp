#include <iostream>
#include "Point.hpp"  // includes Fixed + Point + pointInTriangle

int main(void) {

    Fixed a(2);
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "Testing Fixed class:" << std::endl;

    std::cout << a * b << std::endl;
    std::cout << 2 * (5.05f * 2) << std::endl;


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
