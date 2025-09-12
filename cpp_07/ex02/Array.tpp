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
Array<T>::Array(const Array &other)
	: data_(other.size_ ? new T[other.size_]() : NULL), size_(other.size_)
{
	for (std::size_t i = 0; i < size_; ++i)
		data_[i] = other.data_[i];
}

// Overloaded assignment operator
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);

	T *tmp = other.size_ ? new T[other.size_]() : NULL;

	for (std::size_t i = 0; i < other.size_; ++i)
		tmp[i] = other.data_[i];

	delete[] (data_);

	data_ = tmp;
	size_ = other.size_;

    return (*this);
}

// Destructor
template <typename T>
Array<T>::~Array()
{
    delete[] (data_);
}

// ============ Operator[] Overload ============

template <typename T>
T &Array<T>::operator[](std::size_t index)
{
    if (index >= size_)
        throw std::out_of_range("Array: index out of range");

    return (data_[index]);
}

template <typename T>
const T &Array<T>::operator[](std::size_t index) const
{
    if (index >= size_)
        throw std::out_of_range("Array: index out of range");

    return (data_[index]);
}

// Get size of array
template <typename T>
std::size_t Array<T>::size() const
{
    return (size_);
}
