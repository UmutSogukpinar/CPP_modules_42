#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal()
{
	type_ = "Dog";
	std::cout << "Dog default constructor called" << "\n";
}

// Copy Constructor
Dog::Dog(const Dog &other) : Animal(other)
{
	type_ = other.type_;
	std::cout << "Dog copy constructor called" << "\n";
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called" << "\n";
}

// Overloaded assignment operator
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << "\n";
	if (this != &other)
	{
		Animal::operator=(other);
		type_ = other.type_;
	}
	return (*this);
}

// Member function

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << "\n";
}