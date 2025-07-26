#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

# define ICE	"ice"

class Ice : public AMateria
{
	public:
		// Default Constructor
		Ice();

		// Copy Constructor
		Ice(const Ice & other);

		// Assignment Operator
		Ice & operator=(Ice const & other);

		// Destructor
		~Ice();

		// Clone function
		AMateria *clone() const;

		// Member Function(s)
		void use(ICharacter& target);

};



#endif