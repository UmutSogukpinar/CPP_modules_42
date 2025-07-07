#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

# define CURE "cure"

class Cure: public AMateria
{
	// Default Constructor
	Cure();

	// Copy Constructor
	Cure(Cure const &other);

	// Destructor
	~Cure();

	// Operator overload assignment
	Cure &operator=(Cure const &other);

	// Overrided Functions

	AMateria* clone() const;
	void use(Icharacter & character);

};


#endif