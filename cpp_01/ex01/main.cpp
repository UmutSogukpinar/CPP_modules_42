#include "Zombie.hpp"
#include "cstdlib"

int main() 
{
    const int N = 8;
    std::string name = "Mustapha";

    Zombie* horde = zombieHorde(N, name);
    if (horde) 
    {
        for (int i = 0; i < N; ++i) 
        {
            horde[i].announce();
        }
        delete[] (horde);
    } 
    else 
    {
        std::cerr << "Failed to create zombie horde.\n";
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}
