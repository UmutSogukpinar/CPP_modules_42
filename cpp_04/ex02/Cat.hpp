#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{

private:
	Brain *brain_;

public:
	// Default Constructor
	Cat();

	// Copy Constructor
	Cat(const Cat &other);

	// Assignment Operator
	virtual ~Cat();

	// Overloaded assignment operator
	Cat &operator=(const Cat &other);

	// Member function
	void makeSound() const;
};


#endif