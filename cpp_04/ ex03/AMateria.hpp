#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "iostream"

# define DEFAULT	"default"

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
		~AMateria();

		// * Getter
		std::string const & getType() const; // Returns the materia type

		// * Member Functions
		virtual AMateria* clone() const = 0;
		// TODO: implement later ===>> virtual void use(ICharacter& target);
};

#endif