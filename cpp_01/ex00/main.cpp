#include "Zombie.hpp"
#include <cstdlib>

int	main()
{
	Zombie	*zombie = newZombie("Mus");
	if (!zombie)
		std::cout << "Allocation error!" << "\n";  // ? Does alloc error need to be handled anymore?

	randomChump("Tu");	

	zombie->announce();
	delete zombie;
	return (EXIT_SUCCESS);
}