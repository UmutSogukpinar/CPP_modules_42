#ifndef AAAnimal_HPP
# define AAAnimal_HPP

# include "iostream"

class AAnimal
{
protected:
	std::string type_;

public:
	// Default Constructor
	AAnimal();

	// Copy Constructor
	AAnimal(const AAnimal &other);

	// Assignment Operator
	virtual ~AAnimal();

	// Overloaded assignment operator
	AAnimal &operator=(const AAnimal &other);

	// Getter
	std::string getType() const;

	// Member function(s)
	virtual void makeSound() const = 0;

};


#endif