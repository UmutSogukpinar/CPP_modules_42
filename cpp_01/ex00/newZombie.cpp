#include "Zombie.hpp"

Zombie*	newZombie( std::string name) 
{
	Zombie* zombie = new (std::nothrow) Zombie("Mus");

	return (zombie);
}
