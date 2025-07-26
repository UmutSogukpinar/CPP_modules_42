#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "iostream"
# include "ICharacter.hpp"

# define DEFAULT	"default"

class ICharacter;

class AMateria
{
	protected:
		std::string	type_;
		
	public:

		// * Default Constructor
		AMateria();

		// * Parameterized Constructor
		AMateria(std::string type);

		// * Destructor
		virtual ~AMateria();

		// * Assignment Operator
		AMateria & operator=(AMateria const & other);

		// * Getter
		std::string const & getType() const; // Returns the materia type

		// * Member Functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif