#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

# define ICE "ice"

class Ice: public AMateria
{
	// Default Constructor
	Ice();

	// Copy Constructor
	Ice(Ice const &other);

	// Destructor
	~Ice();

	// Operator overload assignment
	Ice &operator=(Ice const &other);

	// Overrided Functions

	AMateria* clone() const;
	void use(Icharacter & character);

};


#endif