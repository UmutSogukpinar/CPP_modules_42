#include "Cat.hpp"

// Default constructor
Cat::Cat() : AAnimal()
{
	type_ = "Cat";
	std::cout << "Cat default constructor called" << "\n";
}

// Copy Constructor
Cat::Cat(const Cat &other) : AAnimal(other)
{
	type_ = other.type_;
	std::cout << "Cat copy constructor called" << "\n";
	brain_ = new Brain(*other.brain_);
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
		AAnimal::operator=(other);
		type_ = other.type_;
		
		if (brain_)
			delete brain_;

		brain_ = new Brain(*other.brain_);
	}
	return (*this);
}

// ======= Member function =======

void Cat::makeSound() const
{
	std::cout << "Meow" << "\n";
}
