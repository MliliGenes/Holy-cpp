#pragma once

#include <stack>
#include <string>

typedef std::stack<char> stackint;
typedef std::string string;

class RPN {

    private:
        string foramt_str;
        size_t index;

        stackint stack_int;
        string msg_err;

    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        void setFormatStr(const string& str);
        const string& getFormatStr(void) const;

        void eval(void) const;

        char get_next_char(void);
        bool validate(void);
};