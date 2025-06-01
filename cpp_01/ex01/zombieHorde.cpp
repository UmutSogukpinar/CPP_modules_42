#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        return (NULL);
    }

    Zombie* zombie_arr = new (std::nothrow) Zombie[N];
    if (!zombie_arr) 
    {
        std::cerr << "Memory allocation failed!\n";
        return (NULL);
    }

    for (int i = 0; i < N; ++i)
    {
        zombie_arr[i].setName(name);
    }

    return (zombie_arr);
}
