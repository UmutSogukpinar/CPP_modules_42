#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal(), brain_(new Brain())
{
	type_ = "Dog";
	std::cout << "Dog default constructor called" << "\n";
}

// Copy Constructor
Dog::Dog(const Dog &other) : Animal(other), brain_(new Brain(*other.brain_))
{
	type_ = other.type_;
	std::cout << "Dog copy constructor called" << "\n";
}

// Destructor
Dog::~Dog()
{
	delete (brain_);
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
		
		if (brain_)
			delete (brain_);

		brain_ = new Brain(*other.brain_);
	}
	return (*this);
}

Brain* Dog::getBrainAddress() const
{
	return (this->brain_);
}

// ======= Member function(s) =======

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << "\n";
}