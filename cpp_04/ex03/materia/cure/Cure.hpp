#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

# define CURE	"cure"

class Cure : public AMateria
{
	public:
		// Default Constructor
		Cure();

		// Copy Constructor
		Cure(const Cure & other);

		// Assignment Operator
		Cure & operator=(Cure const & other);

		// Destructor
		~Cure();

		// Clone function
		AMateria *clone() const;

		// Member Function(s)
		void use(ICharacter& target);

};



#endif