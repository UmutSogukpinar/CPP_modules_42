#include "Zombie.hpp"


Zombie::Zombie(std::string name)
{
    name_ = name;
}
#
Zombie::~Zombie()
{
	std::cout << name_ << " Destructor called!" << std::endl;
}


void Zombie::announce(void) const
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << "\n";
}