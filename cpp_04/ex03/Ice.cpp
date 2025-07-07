#include "Ice.hpp"

// ======================== Constructors ========================

Ice::Ice() : AMateria(ICE) {}

Ice::Ice(const Ice& other) : AMateria(other) {}

// Destructor
Ice::~Ice() {}

// Assignment operator
Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

// ==================== Overrided Function(s) ====================

void Ice::use(ICharacter& target) // TODO: Implement ICharacter interface
{
	std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

