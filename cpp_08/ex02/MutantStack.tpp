#include "MutantStack.hpp"

// ========== Constructors & Destructor ==========

// Default Constructor
template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>() {}

// Copy Constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
	: std::stack<T>(other) {}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack() {}

// Assignment operator
template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

// ========== Member functions ==========

template <typename T>
void	MutantStack<T>::push(const T& value)
{
	this->c.push_front(value);
}

template <typename T>
void	MutantStack<T>::pop()
{
	this->c.pop_front();
}

template <typename T>
T&	MutantStack<T>::top()
{
	return (this->c.front());
}

// ========== Iterator functions ==========

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return (this->c.end());
}
