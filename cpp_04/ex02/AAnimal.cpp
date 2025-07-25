#include "AAnimal.hpp"

// Default constructor
AAnimal::AAnimal() : type_("Animal")
{
	std::cout << "Animal default constructor called" << "\n";
}

// Copy Constructor
AAnimal::AAnimal(const AAnimal &other) : type_(other.type_)
{
	std::cout << "Animal copy constructor called" << "\n";
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << "\n";
}

// Overloaded assignment operator
AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Animal assignment operator called" << "\n";
	if (this != &other)
	{
		type_ = other.type_;
	}
	return (*this);
}

// Getter
std::string AAnimal::getType() const
{
	return (type_);
}

