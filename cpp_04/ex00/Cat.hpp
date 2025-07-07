#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
  public:
	// Default Constructor
	Cat();

	// Copy Constructor
	Cat(const Cat &other);

	// Assignment Operator
	virtual ~Cat();

	// Overloaded assignment operator
	Cat &operator=(const Cat &other);

	// Member function (inherited)
	void makeSound() const;
};

#endif