#include <iostream>
#include "Span.hpp"

int main() {
    try {
        std::cout << "=== Basic test ===" << std::endl;
        Span sp(10);

        sp.addNumber(1);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(99);
        sp.addNumber(100);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;

        std::cout << "\n=== Range test ===" << std::endl;
        Span sp2(15);

        sp2.addNumberRange(1, 5);   // adds 1 2 3 4 5
        sp2.addNumberRange(10, 12); // adds 10 11 12

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp2.longestSpan() << std::endl;

        std::cout << "\n=== Overflow test ===" << std::endl;
        Span sp3(3);
        sp3.addNumberRange(1, 5); // should throw

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Not enough elements test ===" << std::endl;
        Span sp4(5);
        sp4.addNumber(42);
        std::cout << sp4.shortestSpan() << std::endl; // should throw
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Large Span test ===" << std::endl;
        Span sp5(10000);
        sp5.addNumberRange(1, 10000);
        std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp5.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
