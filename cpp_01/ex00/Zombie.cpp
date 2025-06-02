#include "Zombie.hpp"

Zombie::Zombie(const std::string name): name_(name){}

Zombie::~Zombie()
{
	std::cout << name_ << " Destructor called!" << "\n";
}

void Zombie::announce(void) const
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << "\n";
}
