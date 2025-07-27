#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain *brain_;

public:
	// Default Constructor
	Dog();

	// Copy Constructor
	Dog(const Dog &other);

	// Assignment Operator
	virtual ~Dog();

	// Overloaded assignment operator
	Dog &operator=(const Dog &other);

	// Getter Function
	const Brain* getBrainAddress() const;

	// Member function
	void	makeSound() const;
};


#endif