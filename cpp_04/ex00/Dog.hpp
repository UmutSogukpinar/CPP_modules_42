#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
  public:
	// Default Constructor
	Dog();

	// Copy Constructor
	Dog(const Dog &other);

	// Assignment Operator
	virtual ~Dog();

	// Overloaded assignment operator
	Dog &operator=(const Dog &other);

	// Member function (inherited)
	void makeSound() const;
};

#endif