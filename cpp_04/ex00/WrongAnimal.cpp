#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() : type_("WrongAnimal") 
{
	std::cout << "WrongAnimal default constructor called" << "\n";
}

// Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type_(other.type_) 
{
	std::cout << "WrongAnimal copy constructor called" << "\n";
}

// Destructor
WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal destructor called" << "\n";
}

// Overloaded assignment operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) 
{
	std::cout << "WrongAnimal assignment operator called" << "\n";
	if (this != &other) 
	{
		type_ = other.type_;
	}
	return (*this);
}

// Member function
void WrongAnimal::makeSound() const 
{
	std::cout << "WrongAnimal sound" << "\n";
}