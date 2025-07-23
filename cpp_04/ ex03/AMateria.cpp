#include "AMateria.hpp"

// * Constructor
AMateria::AMateria(): type_(DEFAULT) {}

AMateria::AMateria(std::string type): type_(type) {}


// * Destructor
AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return (type_);
}

// TODO: implement later ====>>>> virtual void use(ICharacter& target);
