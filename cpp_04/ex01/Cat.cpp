#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal(), brain_(new Brain())
{
	type_ = "Cat";
	std::cout << "Cat default constructor called" << "\n";
}

// Copy Constructor 
Cat::Cat(const Cat &other) : Animal(other), brain_(new Brain(*other.brain_))
{
	type_ = other.type_;
	std::cout << "Cat copy constructor called" << "\n";
}

// Destructor
Cat::~Cat()
{
	delete (brain_);
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
