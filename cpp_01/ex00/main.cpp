#include "Zombie.hpp"
#include "cstdlib"

int	main()
{
	randomChump("Tu");
	Zombie	*zombie = newZombie("Mustapha");

	if (!zombie)
	{
		std::cerr << "Allocation error!" << "\n";
		return (EXIT_FAILURE);
	}

	zombie->announce();

	delete (zombie);
	return (EXIT_SUCCESS);
}
