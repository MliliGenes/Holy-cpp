#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    try {
        int found = easyfind(vec, 2);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    std::list<int> list;
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }

    try {
        int found = easyfind(list, 5);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    std::deque<int> dq;
    for (int i = 0; i < 10; ++i) {
        dq.push_back(i);
    }

    try {
        int found = easyfind(dq, 7);
        std::cout << "Found: " << found << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}