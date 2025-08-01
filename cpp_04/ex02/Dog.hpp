#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
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


	// Member function
	void	makeSound() const;
};


#endif
