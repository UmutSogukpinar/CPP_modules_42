#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : name_(name), weapon_(NULL) {}

void HumanB::setWeapon(Weapon& weapon)
{
    weapon_ = &weapon;
}

void HumanB::attack() const
{
    if (weapon_ == NULL)
    {
        std::cout << name_ << " cannot attack" << "\n";
        return;
    }
    std::cout << name_ << " attacks with their " << weapon_->getType() << "\n";
}
