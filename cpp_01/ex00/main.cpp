#include "Zombie.hpp"
#include "cstdlib"

int	main()
{
	randomChump("Tu");
	Zombie	*zombie = newZombie("Mus");

	if (!zombie)
		std::cerr << "Allocation error!" << "\n";

	zombie->announce();

	delete (zombie);
	return (EXIT_SUCCESS);
}
