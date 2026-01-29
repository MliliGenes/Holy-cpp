#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
int easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found");
    }
    return *it;
}