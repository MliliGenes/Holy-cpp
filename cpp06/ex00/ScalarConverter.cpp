#include "ScalarConverter.hpp"
#include <sstream>
#include <string>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    return *this;
}

static void print_scalar(const scalar_t& all) {
    
}

void ScalarConverter::convert(const string& literal) {
    bool conversionSuccess = true;
    std::istringstream input_stream;
    scalar_t scalar;

    if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
        literal == "infinity" || literal == "-infinity") {
        conversionSuccess = false;
        scalar._char = "impossible";
        scalar._int = "impossible";
        if (literal == "nan") {
            scalar._float = "nanf";
            scalar._double = "nan";
        }
        else if (literal == "inf" || literal == "+inf") {
            scalar._float = "inff";
            scalar._double = "inf";
        } else {
            scalar._float = "-inff";
            scalar._double = "-inf";
        }
    }
}