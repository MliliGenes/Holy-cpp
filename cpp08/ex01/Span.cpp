#include "Span.hpp"

Span::Span() {}
Span::~Span() {}

Span::Span(unsigned int n) : cap(n), idx(0) {}

Span::Span(const Span& other) {
    cap = other.cap;
    idx = other.idx;
    vec = other.vec;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        cap = other.cap;
        idx = other.idx;
        vec = other.vec;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (idx >= cap)
        throw std::out_of_range("Span is full");
    vec.push_back(number);
    idx++;
}

void Span::addNumberRange(int start, int end) {
    if (start >= end)
        throw std::out_of_range("end should be strictly bigger than start");

    unsigned int range_size = end - start + 1;
    if (idx + range_size > cap)
        throw std::out_of_range("Span will exceed its capacity");

    for (; start <= end; start++) {
        vec.push_back(start);
        idx++;
    }
}

unsigned int Span::shortestSpan() const {
    if (idx < 2)
        throw std::out_of_range("Not enough numbers to find a span");

    vectorInt sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());

    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sortedVec.size(); i++) {
        unsigned int span = sortedVec[i] - sortedVec[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (idx < 2)
        throw std::out_of_range("Not enough numbers to find a span");

    int minVal = *std::min_element(vec.begin(), vec.end());
    int maxVal = *std::max_element(vec.begin(), vec.end());

    return maxVal - minVal;
}