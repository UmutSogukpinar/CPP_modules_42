#include <cstdlib>
#include "Harl.hpp"

int	main(int size, char **args)
{
	if (size != 2)
	{
		std::cout << "Usage: ./harlFilter <WARNING, ERROR, DEBUG, INFO>" << std::endl;
		return (EXIT_FAILURE);
	}

	Harl harl;
	harl.complain(args[1]);

	return (EXIT_SUCCESS);
}
