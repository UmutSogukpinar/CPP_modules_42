#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	// Default constructor
	WrongCat();

	// Copy Constructor
	WrongCat(const WrongCat &other);

	// Destructor
	~WrongCat();

	// Overloaded assignment operator
	WrongCat &operator=(const WrongCat &other);

	// Member function
	void makeSound() const;
};

#endif