#include "Weapon.hpp"


Weapon::Weapon(const std::string type) : type_(type){}


const std::string& Weapon::getType() const
{
    return (this->type_);
}

void Weapon::setType(const std::string& newType)
{
    this->type_ = newType;
}