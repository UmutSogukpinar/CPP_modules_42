#include "Weapon.hpp"

// Default Constructor
Weapon::Weapon(const std::string& type) : type_(type) {}

// ======= Getters and Setters =======

const std::string& Weapon::getType() const
{
    return (type_);
}

void Weapon::setType(const std::string& newType)
{
    type_ = newType;
}
