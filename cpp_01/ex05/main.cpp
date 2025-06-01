#include "Harl.hpp"
#include "cstdlib"


int main()
{
    Harl harl;

    try
    {
        harl.complain("WARNING");
        harl.complain("ERROR");
        harl.complain("INFO");
        harl.complain("DEBUG");

        harl.complain("NONE");
        harl.complain("UNKNOWN");
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught an exception: " << e.what() << "\n";
        return (EXIT_FAILURE);
    }
	
    return (EXIT_SUCCESS);
}
