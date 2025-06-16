#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() : WrongAnimal()
{
	type_ = "WrongCat";
	std::cout << "WrongCat default constructor called" << "\n";
}

// Copy Constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	type_ = other.type_;
	std::cout << "WrongCat copy constructor called" << "\n";
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << "\n";
}

// Overloaded assignment operator
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assignment operator called" << "\n";
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		type_ = other.type_;
	}
	return (*this);
}

// Member function
void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow" << "\n";
}