#include "Zombie.hpp"
#include "cstdlib"

int	main()
{
	Zombie	*zombie = newZombie("Mus");

	if (!zombie)
		std::cerr << "Allocation error!" << "\n";

	randomChump("Tu");	

	zombie->announce();
	delete zombie;
	return (EXIT_SUCCESS);
}