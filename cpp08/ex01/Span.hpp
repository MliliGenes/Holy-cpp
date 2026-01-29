  #pragma once

#include <vector>

typedef std::vector<int> vectorInt;

class Span {

    private:
        unsigned int    cap;
        unsigned int    idx;
        vectorInt       vec;

    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void            addNumber(int number);
        void            addNumberRange(int start, int end);

        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;

    private:
        Span();
};