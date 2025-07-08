#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "iostream"
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type_;

	public:

		// Default Constructor
		AMateria();

		// Parameterized Constructor
		AMateria(std::string type); // !? Is it necessary

		// Copy Constructor
		AMateria(AMateria const &other);

		// Destructor
		~AMateria();

		// Assignment operator overload
		AMateria &operator=(AMateria const &other);

		// =========== Getters & Setters ===========

		std::string const &getType() const;


		// =========== Virtual Function(s) ===========

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


#endif