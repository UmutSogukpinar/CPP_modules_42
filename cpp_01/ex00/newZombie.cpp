#include "Zombie.hpp"

Zombie*	newZombie(std::string name) 
{
	Zombie* zombie = new (std::nothrow) Zombie(name);

	return (zombie);
}
