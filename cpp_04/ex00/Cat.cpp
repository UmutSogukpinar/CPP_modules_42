#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal()
{
	type_ = "Cat";
	std::cout << "Cat default constructor called" << "\n";
}

// Copy Constructor
Cat::Cat(const Cat &other) : Animal(other)
{
	type_ = other.type_;
	std::cout << "Cat copy constructor called" << "\n";
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat destructor called" << "\n";
}

// Overloaded assignment operator
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called" << "\n";
	if (this != &other)
	{
		Animal::operator=(other);
		type_ = other.type_;
	}
	return (*this);
}

// Member function

void Cat::makeSound() const
{
	std::cout << "Meow" << "\n";
}
