#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <cctype>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

// print the char format
void handle_char(const string& literal) {
    // pseudo-literals are impossible to convert to char
    if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
        literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    // single non-digit character literal: print the character
    if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))) {
        char c = literal[0];
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        return;
    }

    // otherwise try to parse as a number
    std::istringstream iss(literal);
    double value;
    iss >> value;
    if (iss.fail() || !iss.eof() || !std::isfinite(value)) {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    // value must be an integer within ASCII range
    if (value < 0 || value > 127 || std::floor(value) != value) {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(value);
    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void handle_int(const string& literal) {
    // pseudo-literals are impossible to convert to int
    if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
        literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::cout << "int: impossible" << std::endl;
        return;
    }

    // single non-digit character literal: convert to its ASCII value
    if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))) {
        int ascii_value = static_cast<int>(literal[0]);
        std::cout << "int: " << ascii_value << std::endl;
        return;
    }

    // otherwise try to parse as a number
    // allow float-style literals with trailing 'f' (e.g., "4.2f")
    string token = literal;
    if (token.length() > 1 && token[token.length() - 1] == 'f')
        token = token.substr(0, token.length() - 1);

    std::istringstream iss(token);
    double value;
    iss >> value;
    if (iss.fail() || !iss.eof() || !std::isfinite(value) ||
        value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX)) {
        std::cout << "int: impossible" << std::endl;
        return;
    }

    int int_value = static_cast<int>(value);
    std::cout << "int: " << int_value << std::endl;
}

void handle_float(const string& literal) {
    // handle pseudo-literals first
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff") {
        std::cout << "float: +inff" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
        return;
    }

    // single non-digit character literal: print its ASCII as float
    if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))) {
        float f = static_cast<float>(literal[0]);
        std::ostringstream oss;
        if (std::isfinite(f) && std::floor(f) == f) {
            oss.setf(std::ios::fixed);
            oss.precision(1);
            oss << f;
        } else {
            oss << f;
        }
        std::cout << "float: " << oss.str() << "f" << std::endl;
        return;
    }

    // allow a trailing 'f' for float literals (e.g., "4.2f")
    string token = literal;
    if (token.length() > 1 && token[token.length() - 1] == 'f') {
        token = token.substr(0, token.length() - 1);
    }

    std::istringstream iss(token);
    double value;
    iss >> value;
    if (iss.fail() || !iss.eof() || !std::isfinite(value)) {
        std::cout << "float: impossible" << std::endl;
        return;
    }

    float fvalue = static_cast<float>(value);
    std::ostringstream oss;
    if (std::isfinite(static_cast<double>(fvalue)) && std::floor(fvalue) == fvalue) {
        oss.setf(std::ios::fixed);
        oss.precision(1);
        oss << fvalue;
    } else {
        oss << fvalue;
    }
    std::cout << "float: " << oss.str() << "f" << std::endl;
}

// print the double format
void handle_double(const string& literal) {
    // handle pseudo-literals first
    if (literal == "nan" || literal == "nanf") {
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff") {
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "double: -inf" << std::endl;
        return;
    }

    // single non-digit character literal: print its ASCII as double
    if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))) {
        double d = static_cast<double>(literal[0]);
        std::ostringstream oss;
        if (std::isfinite(d) && std::floor(d) == d) {
            oss.setf(std::ios::fixed);
            oss.precision(1);
            oss << d;
        } else {
            oss << d;
        }
        std::cout << "double: " << oss.str() << std::endl;
        return;
    }

    // allow a trailing 'f' for float-style literals (e.g., "4.2f")
    string token = literal;
    if (token.length() > 1 && token[token.length() - 1] == 'f') {
        token = token.substr(0, token.length() - 1);
    }

    std::istringstream iss(token);
    double value;
    iss >> value;
    if (iss.fail() || !iss.eof() || !std::isfinite(value)) {
        std::cout << "double: impossible" << std::endl;
        return;
    }

    std::ostringstream oss;
    if (std::isfinite(value) && std::floor(value) == value) {
        oss.setf(std::ios::fixed);
        oss.precision(1);
        oss << value;
    } else {
        oss << value;
    }
    std::cout << "double: " << oss.str() << std::endl;
}

void ScalarConverter::convert(const string& literal) {
    handle_char(literal);
    handle_int(literal);
    handle_float(literal);
    handle_double(literal);
}