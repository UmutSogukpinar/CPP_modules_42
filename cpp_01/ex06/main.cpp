#include <cstdlib>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            throw std::invalid_argument("Usage: ./harlFilter <DEBUG, INFO, WARNING, ERROR>");
        }

        Harl harl;
        harl.complain(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

