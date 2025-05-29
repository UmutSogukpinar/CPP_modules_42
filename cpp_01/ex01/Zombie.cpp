#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << name_ << " Destructor called!" << "\n";
}

void Zombie::announce(void) const
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << "\n";
}

void Zombie::setName(std::string name)
{
    name_ = name;
}