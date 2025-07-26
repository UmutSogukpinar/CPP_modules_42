#include "Cure.hpp"

// * ============================== Constructors ==============================


Cure::Cure() : AMateria(CURE) {}

Cure::Cure(const Cure & other) : AMateria(other.type_) {}

Cure & Cure::operator=(Cure const & other) 
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

Cure::~Cure() {};


// * ============================== Member Function(s) ==============================

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << "\n";
}
