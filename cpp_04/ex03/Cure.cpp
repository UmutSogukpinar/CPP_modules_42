#include "Cure.hpp"

// ======================== Constructors ========================

Cure::Cure() : AMateria(CURE) {}

Cure::Cure(const Cure& other) : AMateria(other) {}

// Destructor
Cure::~Cure() {}

// Assignment operator
Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

// ==================== Overrided Function(s) ====================

void Cure::use(ICharacter& target) // TODO: Implement ICharacter interface
{
	std::cout << "Cure: * heals " << target.getName() << "'s wounds *" << "\n";
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

