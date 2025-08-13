#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T          *data_;
        std::size_t size_;
    
    public:
        Array();
        explicit Array(unsigned int n);
        Array(Array const &other);
        Array &operator=(Array const &rhs);
        ~Array();

        T       &operator[](std::size_t idx);
        T const &operator[](std::size_t idx) const;

        std::size_t size() const;

};

#include "Array.tpp"

#endif
