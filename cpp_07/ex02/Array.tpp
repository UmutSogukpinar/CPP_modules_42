#include "Array.hpp"

// Default Constructor
template <typename T>
Array<T>::Array() : data_(NULL), size_(0) {}

// Parameterised Constructor
template <typename T>
Array<T>::Array(unsigned int n)
    : data_(n ? new T[n]() : NULL), size_(n) {}

// Copy Constructor
template <typename T>
Array<T>::Array(Array const &other)
    : data_(other.size_ ? new T[other.size_]() : NULL), size_(other.size_)
{
    for (std::size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
}

// Overloaded assignment operator
template <typename T>
Array<T> &Array<T>::operator=(Array const &arr)
{
    if (this == &arr)
        return (*this);

    T *tmp = arr.size_ ? new T[arr.size_]() : NULL;
    for (std::size_t i = 0; i < arr.size_; ++i)
        tmp[i] = arr.data_[i];

    delete[] (data_);

    data_ = tmp;
    size_ = arr.size_;

    return (*this);
}

// Destructor
template <typename T>
Array<T>::~Array()
{
    delete[] (data_);
}

template <typename T>
T &Array<T>::operator[](std::size_t index)
{
    if (index >= size_)
        throw std::out_of_range("Array: index out of range");

    return (data_[index]);
}

template <typename T>
T const &Array<T>::operator[](std::size_t index) const
{
    if (index >= size_)
        throw std::out_of_range("Array: index out of range");

    return (data_[index]);
}

template <typename T>
std::size_t Array<T>::size() const
{
    return (size_);
}
