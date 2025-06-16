#include "Animal.hpp"

// Default constructor
Animal::Animal() : type_("Animal")
{
	std::cout << "Animal default constructor called" << "\n";
}

// Copy Constructor
Animal::Animal(const Animal &other) : type_(other.type_)
{
	std::cout << "Animal copy constructor called" << "\n";
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal destructor called" << "\n";
}

// Overloaded assignment operator
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignment operator called" << "\n";
	if (this != &other)
	{
		type_ = other.type_;
	}
	return (*this);
}

// Getter
std::string Animal::getType() const
{
	return (type_);
}

// ========== Member function(s) ==========

void Animal::makeSound() const
{
	std::cout << "Animal sound" << "\n";
}
