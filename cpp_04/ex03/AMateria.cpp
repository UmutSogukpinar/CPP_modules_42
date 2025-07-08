#include "AMateria.hpp"

// ================== Constructors ==================

AMateria::AMateria(): type_("") {}

AMateria::AMateria(std::string type): type_(type) {}

AMateria::AMateria(const AMateria &other): type_(other.type_) {}


// Destructor
AMateria::~AMateria() {}

// Assignment Operator
AMateria& AMateria::operator=(AMateria const &other)
{
	if (this != &other)
		type_ = other.type_;

	return (*this);
}

// =========== Getters & Setters ===========

std::string	const& AMateria::getType() const
{
	return (this->type_);
}


// =========== Member Function(s) ===========

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses generic materia on " << target.getName() << " *\n";
}
