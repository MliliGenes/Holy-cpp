#include "RPN.hpp"
#include <iostream>

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN& other) {
    format_str = other.format_str;
    index = other.index;
    stack_int = other.stack_int;
    msg_err = other.msg_err;
}

RPN& RPN::operator=(const RPN& other) {
    if (this == &other)
        return *this;
    format_str = other.format_str;
    index = other.index;
    stack_int = other.stack_int;
    msg_err = other.msg_err;
    return *this;
}

void RPN::setFormatStr(const string& str) {
    format_str = str;
}

const string& RPN::getFormatStr() const {
    return format_str;
}

static bool isWhitespace(int c) {
    return std::isspace(static_cast<unsigned char>(c));
}

static bool isUselessChar(char c) {
    return !(std::isdigit(c) || c == '-' || c == '+' || c == '/' || c == '*');
}

int RPN::get_next_char() {
    for (; index < format_str.length(); index++) {
        if (!isWhitespace(format_str[index])) {
            if (isUselessChar(format_str[index]))
                return -1;
            if (index + 1 < format_str.length() && !isUselessChar(format_str[index + 1]))
                return -1;
            return format_str[index++];
        }
    }
    return 0;
}

void RPN::eval() {
    if (!validate()) {
        std::cerr << "Error" << std::endl;
        return;
    }
    index = 0;
    int c;
    int res, a, b;
    while ((c = get_next_char()) != 0) {
        if (std::isdigit(c))
            stack_int.push(static_cast<int>(c - '0'));
        else {
            if (stack_int.size() < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }
            b = stack_int.top();
            stack_int.pop();
            a = stack_int.top();
            stack_int.pop();
            switch (c) {
                case '+':
                    res = a + b;
                    stack_int.push(res);
                    break;
                case '-':
                    res = a - b;
                    stack_int.push(res);
                    break;
                case '*':
                    res = a * b;
                    stack_int.push(res);
                    break;
                case '/':
                    res = a / b;
                    stack_int.push(res);
                    break;
                default:
                    std::cerr << "wtf" << std::endl;
            }
        }
    }
    std::cout << stack_int.top() << std::endl;
}

bool RPN::validate() {
    int c;
    while ((c = get_next_char()) != 0) {
        if (c == -1)
            return false;
    }
    return true;
}