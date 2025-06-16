#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "iostream"

class Animal
{
protected:
	std::string type_;

public:
	// Default Constructor
	Animal();

	// Copy Constructor
	Animal(const Animal &other);

	// Assignment Operator
	virtual ~Animal();

	// Overloaded assignment operator
	Animal &operator=(const Animal &other);

	// Getter
	std::string getType() const;

	// Member function(s)
	virtual void makeSound() const;

};


#endif