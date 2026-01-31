#include "RPN.hpp"
#include <iostream>

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN& other) {
    foramt_str = other.foramt_str;
    index = other.index;
    stack_int = other.stack_int;
    msg_err = other.msg_err;
}

RPN& RPN::operator=(const RPN& other) {
    if (this == &other)
        return *this;
    foramt_str = other.foramt_str;
    index = other.index;
    stack_int = other.stack_int;
    msg_err = other.msg_err;
    return *this;
}

void RPN::setFormatStr(const string& str) {
    foramt_str = str;
}

const string& RPN::getFormatStr() const {
    return foramt_str;
}

static bool isWhitespace(char c) {
    return std::isspace(static_cast<unsigned char>(c));
}

static bool isUselessChar(char c) {
    return !(std::isdigit(c) || );
}

char RPN::get_next_char() {
    for (; index < foramt_str.length(); index++) {
        if (!isWhitespace(foramt_str[index]) && ) {
            return foramt_str[index];
        }
    }
    if (index == foramt_str.length())
        return 0;
    return -1;
}

void RPN::eval() const {
    // if (!validate()) {
    //     std::cout << "" << std::endl;
    //     return;
    // }
}

bool RPN::validate() {
    char c;
    while (true) {
        c = get_next_char();
        if (c == -1)
            return false;
        if (c == 0)
            return true;
    }

    return true;
}