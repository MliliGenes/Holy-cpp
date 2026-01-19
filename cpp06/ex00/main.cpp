#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: provide some input dummy" << std::endl;
        return 1;
    }

    string literal = av[1];
    Scalar::convert(literal);
}