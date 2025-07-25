#include "Ice.hpp"

Ice::Ice() : AMateria(ICE) {}

Ice::Ice(const Ice & other) : AMateria(other.type_) {}

Ice & Ice::operator=(Ice const & other) 
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

Ice::~Ice() {};
