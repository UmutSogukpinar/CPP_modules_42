#include <stdexcept>
#include "cstdlib"
#include "ClapTrap.hpp"

int main()
{
    try
    {
        std::cout << "\n=== TEST 0: Default Constructor Test ===" << "\n";
        ClapTrap defaultFighter; // Default constructor

        std::cout << "\n=== TEST 1: Parameterized Constructor Test ===" << "\n";
        ClapTrap fighter1("Anakin");
        ClapTrap fighter2("Obi-Wan");

        std::cout << "\n=== TEST 2: Copy Constructor Test ===" << "\n";
        ClapTrap copiedFighter(fighter1); // Copy constructor

        std::cout << "\n=== TEST 3: Assignment Operator Test ===" << "\n";
        ClapTrap assignedFighter;
        assignedFighter = fighter2; // Assignment operator

        std::cout << "\n=== BATTLE START ===" << "\n";

        std::cout << "\n--- ROUND 1 ---" << "\n";
        fighter1.attack("Obi-Wan");
        fighter2.takeDamage(7);

        std::cout << "\n--- ROUND 2 ---" << "\n";
        fighter2.attack("Anakin");
        fighter1.takeDamage(5);

        std::cout << "\n--- SELF REPAIR ---" << "\n";
        fighter1.beRepaired(5);
        fighter2.beRepaired(3);

        std::cout << "\n--- ENERGY DRAIN TEST ---" << "\n";
        for (int i = 0; i < 12; ++i)
        {
            fighter1.attack("Training Dummy");
        }

        std::cout << "\n--- CRITICAL DAMAGE TEST ---" << "\n";
        fighter2.takeDamage(50);
        fighter2.takeDamage(60);   // Overkill testing
        fighter2.attack("Anakin"); // Dead man is not supposed to attack

        std::cout << "\n--- ZOMBIE REPAIR TEST ---" << "\n";
        fighter2.beRepaired(20); // Dead man is not supposed to heal

        std::cout << "\n=== BATTLE END ===" << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught during battle: " << e.what() << "\n";
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
