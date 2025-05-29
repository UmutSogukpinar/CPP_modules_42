#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {}

void HumanB::setWeapon(Weapon& weapon)
{
    weapon_ = &weapon;
}

void HumanB::attack() const
{
    std::cout << name_ << " attacks with their " << (weapon_)->getType() << "\n";
}
