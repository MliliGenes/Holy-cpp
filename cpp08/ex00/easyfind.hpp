#pragma once

#include <algorithm>

template <typename T>
int easyfind(T& container, int value) {
    typename T::iterator it;
    if ((it = std::find(container.begin(), container.end(), value)) != container.end()) {
        return *it;
    }
    throw std::runtime_error("Value not found");
}