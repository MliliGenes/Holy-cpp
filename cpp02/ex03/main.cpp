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
    Point A(1.0f, 1.0f);
    Point B(5.0f, 0.0f);
    Point C(3.0f, 3.0f);

    Point P(3.0f, .0f);

    std::cout << (P.getx() - B.getx())
            << " * "
            << (A.gety() - B.gety())
            << " - "
            << (A.getx() - B.getx()) << std::endl;

    std::cout << (bsp(A, B, C, P) ? "inside" : "outside")
            << std::endl;

    return 0;
}
