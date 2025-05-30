#include "Harl.hpp"
#include "cstdlib"

int	main()
{
	Harl harl;

	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("DEBUG");

	harl.complain("NONE");
    harl.complain("UNKNOWN");

	return (EXIT_SUCCESS);
}
