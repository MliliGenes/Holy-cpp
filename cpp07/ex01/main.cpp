#include <iostream>
#include "iter.hpp"

// Non-const reference - can modify
void incrementInt(int& n) {
    n++;
}

// Const reference - read-only
void printInt(const int& n) {
    std::cout << n << " ";
}

// Template function
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

template <typename T>
void doubleValue(T& element) {
    element *= 2;
}

int main() {
    std::cout << "=== Testing iter function ===" << std::endl << std::endl;

    // Test 1: Modify integers
    std::cout << "Test 1: Increment integers" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t size = 5;
    
    std::cout << "Before: ";
    iter(intArray, size, printInt);
    std::cout << std::endl;
    
    iter(intArray, size, incrementInt);
    
    std::cout << "After:  ";
    iter(intArray, size, printInt);
    std::cout << std::endl << std::endl;

    // Test 2: Template function with doubles
    std::cout << "Test 2: Double each value" << std::endl;
    double doubleArray[] = {1.5, 2.5, 3.5};
    
    std::cout << "Before: ";
    iter(doubleArray, 3, printElement<double>);
    std::cout << std::endl;
    
    iter(doubleArray, 3, doubleValue<double>);
    
    std::cout << "After:  ";
    iter(doubleArray, 3, printElement<double>);
    std::cout << std::endl << std::endl;

    // Test 3: Const array
    std::cout << "Test 3: Const array (read-only)" << std::endl;
    const int constArray[] = {10, 20, 30};
    std::cout << "Output: ";
    iter(constArray, 3, printElement<int>);
    std::cout << std::endl << std::endl;

    // Test 4: Strings
    std::cout << "Test 4: String array" << std::endl;
    std::string strings[] = {"hello", "world", "test"};
    std::cout << "Output: ";
    iter(strings, 3, printElement<std::string>);
    std::cout << std::endl << std::endl;

    std::cout << "=== All tests completed ===" << std::endl;

    return 0;
}