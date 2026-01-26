#pragma once

#include <cstddef>
#include <exception>
#include <iostream>
#include <new>

template <typename T>
class Array {

    private:
        T*        _array;
        size_t    _n;

    public:
        Array(void) : _n(0) {
            try {
                _array = new T[0];
            } catch (std::bad_alloc& e) {
                std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            }
        }

        ~Array(void) {
            delete[] _array;
        }

        Array(unsigned int n) : _n(n) {
            try {
                _array = new T[n];
                for (size_t i = 0; i < n; i++)
                    _array[i] = T();
            }
            catch (std::bad_alloc& e) {
                std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            }
        }

        Array(const Array& other) : _n(other._n) {
            try {
                _array = new T[_n];
                for (size_t i = 0; i < _n; i++)
                    _array[i] = other._array[i];
            }
            catch (std::bad_alloc& e) {
                std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            }
        }

        Array& operator=(const Array& other) {
            if (this == &other)
                return  *this;
            delete[] _array;
            _n = other._n;
            try {
                _array = new T[_n];
                for (size_t i = 0; i < _n; i++)
                    _array[i] = other._array[i];
            }
            catch (std::bad_alloc& e) {
                std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            }
            return *this;
        }

        T& operator[](size_t index) {
            if (index >= _n)
                throw std::exception();
            return _array[index];
        }

        const T& operator[](size_t index) const {
            if (index >= _n)
                throw std::exception();
            return _array[index];
        }

        size_t size(void) const {
            return _n;
        }

};