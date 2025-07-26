#include "AMateria.hpp"

// * ==================== Constructors ====================

AMateria::AMateria(): type_(DEFAULT) {}

AMateria::AMateria(std::string type): type_(type) {}

AMateria::AMateria(AMateria const & other): type_(other.type_) {}


// * Assignment Operator

AMateria & AMateria::operator=(AMateria const & other)
{
	if (this != &other)
	{
		this->type_ = other.type_;
	}
	return (*this);
}

// * Destructor
AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return (type_);
}

// * ============================== Member Function(s) ==============================

void AMateria::use(ICharacter& target)
{
	std::cout << "* abstract materia is used on " << target.getName()
	          << " but it has no defined effect *" << "\n";
}


