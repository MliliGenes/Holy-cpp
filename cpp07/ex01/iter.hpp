#pragma once

#include <cstddef>

template <typename T, typename Fun>
void iter(T* array, size_t size, Fun fun) {
    if (!array || !size)
        return;
    for (size_t i = 0; i < size; i++)
        fun(array[i]);
}