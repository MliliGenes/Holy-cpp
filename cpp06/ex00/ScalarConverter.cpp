#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cerrno>
#include <limits>

// Private constructors/destructors
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) { 
    (void)other; 
    return *this; 
}

static bool isChar(const string &literal) {
    return literal.length() == 1 && !isdigit(literal[0]);
}

static bool isInt(const string &literal) {
    if (literal.empty()) return false;
    
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i = 1;
    
    if (i >= literal.length()) return false;
    
    for (; i < literal.length(); i++) {
        if (!isdigit(literal[i]))
            return false;
    }
    
    // Check range
    errno = 0;
    long val = strtol(literal.c_str(), NULL, 10);
    if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
        return false;
    
    return true;
}

static bool isFloat(const string &literal) {
    if (literal.empty()) return false;
    
    // Special cases
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
        return true;
    
    if (literal[literal.length() - 1] != 'f')
        return false;
    
    string numPart = literal.substr(0, literal.length() - 1);
    if (numPart.empty()) return false;
    
    size_t i = 0;
    if (numPart[0] == '+' || numPart[0] == '-')
        i = 1;
    
    bool hasDot = false;
    bool hasDigitBeforeDot = false;
    bool hasDigitAfterDot = false;
    
    for (; i < numPart.length(); i++) {
        if (numPart[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (isdigit(numPart[i])) {
            if (!hasDot)
                hasDigitBeforeDot = true;
            else
                hasDigitAfterDot = true;
        } else {
            return false;
        }
    }
    
    return hasDot && hasDigitBeforeDot && hasDigitAfterDot;
}

static bool isDouble(const string &literal) {
    if (literal.empty()) return false;
    
    // Special cases
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
        return true;
    
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i = 1;
    
    bool hasDot = false;
    bool hasDigitBeforeDot = false;
    bool hasDigitAfterDot = false;
    
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (isdigit(literal[i])) {
            if (!hasDot)
                hasDigitBeforeDot = true;
            else
                hasDigitAfterDot = true;
        } else {
            return false;
        }
    }
    
    return hasDot && hasDigitBeforeDot && hasDigitAfterDot;
}

static Type detectType(const string &literal) {
    if (isChar(literal)) return CHAR;
    if (isInt(literal)) return INT;
    if (isFloat(literal)) return FLOAT;
    if (isDouble(literal)) return DOUBLE;
    return INVALID;
}

static void printChar(char c, bool impossible, bool nonDisplayable) {
    std::cout << "char: ";
    if (impossible)
        std::cout << "impossible";
    else if (nonDisplayable)
        std::cout << "Non displayable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;
}

static void printInt(int i, bool impossible) {
    std::cout << "int: ";
    if (impossible)
        std::cout << "impossible";
    else
        std::cout << i;
    std::cout << std::endl;
}

static void printFloat(float f) {
    std::cout << "float: ";
    if (std::isnan(f))
        std::cout << "nanf";
    else if (std::isinf(f)) {
        if (f > 0)
            std::cout << "+inff";
        else
            std::cout << "-inff";
    } else {
        std::cout << std::fixed << std::setprecision(1) << f << "f";
    }
    std::cout << std::endl;
}

static void printDouble(double d) {
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan";
    else if (std::isinf(d)) {
        if (d > 0)
            std::cout << "+inf";
        else
            std::cout << "-inf";
    } else {
        std::cout << std::fixed << std::setprecision(1) << d;
    }
    std::cout << std::endl;
}

void ScalarConverter::convert(const string &literal) {
    Type type = detectType(literal);
    
    if (type == INVALID) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    
    bool charImpossible = false;
    bool intImpossible = false;
    bool charNonDisplayable = false;
    
    // Convert based on detected type
    switch (type) {
        case CHAR:
            c = literal[0];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
            
        case INT:
            i = atoi(literal.c_str());
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break;
            
        case FLOAT:
            // Handle special float values
            if (literal == "nan") {
                f = std::numeric_limits<float>::quiet_NaN();
            } else if (literal == "+inf" || literal == "inf") {
                f = std::numeric_limits<float>::infinity();
            } else if (literal == "-inf") {
                f = -std::numeric_limits<float>::infinity();
            } else {
                f = static_cast<float>(atof(literal.c_str()));
            }
            
            if (std::isnan(f) || std::isinf(f)) {
                charImpossible = true;
                intImpossible = true;
            } else {
                i = static_cast<int>(f);
                c = static_cast<char>(f);
            }
            d = static_cast<double>(f);
            break; 
            
        case DOUBLE:
            // Handle special double values
            if (literal == "nan") {
                d = std::numeric_limits<double>::quiet_NaN();
            } else if (literal == "+inf" || literal == "inf") {
                d = std::numeric_limits<double>::infinity();
            } else if (literal == "-inf") {
                d = -std::numeric_limits<double>::infinity();
            } else {
                d = atof(literal.c_str());
            }
            
            if (std::isnan(d) || std::isinf(d)) {
                charImpossible = true;
                intImpossible = true;
            } else {
                i = static_cast<int>(d);
                c = static_cast<char>(d);
                f = static_cast<float>(d);
            }
            break;
            
        default:
            break;
    }
    
    // Check if char is displayable
    if (!charImpossible && (c < 32 || c > 126))
        charNonDisplayable = true;
    
    // Print results
    printChar(c, charImpossible, charNonDisplayable);
    printInt(i, intImpossible);
    printFloat(f);
    printDouble(d);
}