#pragma once

#include <stack>
#include <string>

typedef std::stack<int> stackint;
typedef std::string string;

class RPN {

    private:
        string format_str;
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

        void eval(void);
        int get_next_char(void);

    private:
        bool validate(void);
};