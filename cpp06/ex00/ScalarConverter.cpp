#include "ScalarConverter.hpp"
#include <cerrno>
#include <iomanip>
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

// // print the char format
// void handle_char(const string& literal) {
//     // pseudo-literals are impossible to convert to char
//     if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
//         literal == "nanf" || literal == "+inff" || literal == "-inff") {
//         std::cout << "char: impossible" << std::endl;
//         return;
//     }

//     // single non-digit character literal: print the character
//     if (literal.length() == 1 && !std::isdigit(static_cast<char>(literal[0]))) {
//         char c = literal[0];
//         if (std::isprint(static_cast<char>(c)))
//             std::cout << "char: '" << c << "'" << std::endl;
//         else
//             std::cout << "char: Non displayable" << std::endl;
//         return;
//     }

//     // otherwise try to parse as a number
//     std::istringstream iss(literal);
//     double value;
//     iss >> value;
//     if (iss.fail() || !iss.eof() || !std::isfinite(value)) {
//         std::cout << "char: impossible" << std::endl;
//         return;
//     }

//     // value must be an integer within ASCII range
//     if (value < 0 || value > 127 || std::floor(value) != value) {
//         std::cout << "char: impossible" << std::endl;
//         return;
//     }

//     char c = static_cast<char>(value);
//     if (std::isprint(static_cast<char>(c)))
//         std::cout << "char: '" << c << "'" << std::endl;
//     else
//         std::cout << "char: Non displayable" << std::endl;
// }

// void handle_int(const string& literal) {
//     // pseudo-literals are impossible to convert to int
//     if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
//         literal == "nanf" || literal == "+inff" || literal == "-inff") {
//         std::cout << "int: impossible" << std::endl;
//         return;
//     }

//     // single non-digit character literal: convert to its ASCII value
//     if (literal.length() == 1 && !std::isdigit(static_cast<char>(literal[0]))) {
//         int ascii_value = static_cast<int>(literal[0]);
//         std::cout << "int: " << ascii_value << std::endl;
//         return;
//     }

//     // otherwise try to parse as a number
//     // allow float-style literals with trailing 'f' (e.g., "4.2f")
//     string token = literal;
//     if (token.length() > 1 && token[token.length() - 1] == 'f')
//         token = token.substr(0, token.length() - 1);

//     std::istringstream iss(token);
//     double value;
//     iss >> value;
//     if (iss.fail() || !iss.eof() || !std::isfinite(value) ||
//         value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX)) {
//         std::cout << "int: impossible" << std::endl;
//         return;
//     }

//     int int_value = static_cast<int>(value);
//     std::cout << "int: " << int_value << std::endl;
// }

// void handle_float(const string& literal) {
//     // handle pseudo-literals first
//     if (literal == "nan" || literal == "nanf") {
//         std::cout << "float: nanf" << std::endl;
//         return;
//     }
//     if (literal == "+inf" || literal == "+inff") {
//         std::cout << "float: +inff" << std::endl;
//         return;
//     }
//     if (literal == "-inf" || literal == "-inff") {
//         std::cout << "float: -inff" << std::endl;
//         return;
//     }

//     // single non-digit character literal: print its ASCII as float
//     if (literal.length() == 1 && !std::isdigit(static_cast<char>(literal[0]))) {
//         float f = static_cast<float>(literal[0]);
//         std::ostringstream oss;
//         if (std::isfinite(f) && std::floor(f) == f) {
//             oss.setf(std::ios::fixed);
//             oss.precision(1);
//             oss << f;
//         } else {
//             oss << f;
//         }
//         std::cout << "float: " << oss.str() << "f" << std::endl;
//         return;
//     }

//     // allow a trailing 'f' for float literals (e.g., "4.2f")
//     string token = literal;
//     if (token.length() > 1 && token[token.length() - 1] == 'f') {
//         token = token.substr(0, token.length() - 1);
//     }

//     std::istringstream iss(token);
//     double value;
//     iss >> value;
//     if (iss.fail() || !iss.eof() || !std::isfinite(value)) {
//         std::cout << "float: impossible" << std::endl;
//         return;
//     }

//     float fvalue = static_cast<float>(value);
//     std::ostringstream oss;
//     if (std::isfinite(static_cast<double>(fvalue)) && std::floor(fvalue) == fvalue) {
//         oss.setf(std::ios::fixed);
//         oss.precision(1);
//         oss << fvalue;
//     } else {
//         oss << fvalue;
//     }
//     std::cout << "float: " << oss.str() << "f" << std::endl;
// }

// // print the double format
// void handle_double(const string& literal) {
//     // handle pseudo-literals first
//     if (literal == "nan" || literal == "nanf") {
//         std::cout << "double: nan" << std::endl;
//         return;
//     }
//     if (literal == "+inf" || literal == "+inff") {
//         std::cout << "double: +inf" << std::endl;
//         return;
//     }
//     if (literal == "-inf" || literal == "-inff") {
//         std::cout << "double: -inf" << std::endl;
//         return;
//     }

//     // single non-digit character literal: print its ASCII as double
//     if (literal.length() == 1 && !std::isdigit(static_cast<char>(literal[0]))) {
//         double d = static_cast<double>(literal[0]);
//         std::ostringstream oss;
//         if (std::isfinite(d) && std::floor(d) == d) {
//             oss.setf(std::ios::fixed);
//             oss.precision(1);
//             oss << d;
//         } else {
//             oss << d;
//         }
//         std::cout << "double: " << oss.str() << std::endl;
//         return;
//     }

//     // allow a trailing 'f' for float-style literals (e.g., "4.2f")
//     string token = literal;
//     if (token.length() > 1 && token[token.length() - 1] == 'f') {
//         token = token.substr(0, token.length() - 1);
//     }

//     std::istringstream iss(token);
//     double value;
//     iss >> value;
//     if (iss.fail() || !iss.eof() || !std::isfinite(value)) {
//         std::cout << "double: impossible" << std::endl;
//         return;
//     }

//     std::ostringstream oss;
//     if (std::isfinite(value) && std::floor(value) == value) {
//         oss.setf(std::ios::fixed);
//         oss.precision(1);
//         oss << value;
//     } else {
//         oss << value;
//     }
//     std::cout << "double: " << oss.str() << std::endl;
// }

// void ScalarConverter::convert(const string& literal) {
//     handle_char(literal);
//     handle_int(literal);
//     handle_float(literal);
//     handle_double(literal);
// }

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
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
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
            f = static_cast<float>(atof(literal.c_str()));
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
            d = atof(literal.c_str());
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