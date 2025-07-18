#include <stdexcept>
#include "FragTrap.hpp"

int main()
{
    try
    {
        std::cout << "\n=== TEST 0: Default Constructor Test ===" << std::endl;
        FragTrap defaultFighter; // Default constructor

        std::cout << "\n=== TEST 1: Parameterized Constructor Test ===" << std::endl;
        FragTrap fighter1("Anakin");
        FragTrap fighter2("Obi-Wan");

        std::cout << "\n=== TEST 2: Copy Constructor Test ===" << std::endl;
        FragTrap fighter3(fighter1); // Copy constructor
        fighter3.highFivesGuys();

        std::cout << "\n=== TEST 3: Assignment Operator Test ===" << std::endl;
        FragTrap fighter4;   // Default constructor
        fighter4 = fighter2; // Basic assignment
        fighter4.attack("Battle Droids");

        // Chain assignment test
        std::cout << "\n--- Chain Assignment Test ---" << std::endl;
        FragTrap fighter5("R2-D2");
        FragTrap fighter6("Padme");
        fighter5 = fighter6 = fighter2; // Chain assignment, fighter6 gets fighter2, fighter5 gets fighter6
        fighter5.attack("Battle Droids");
        fighter6.attack("Battle Droids");

        // Assign a destroyed fighter
        std::cout << "\n--- Assignment After Destroyed State ---" << std::endl;
        fighter5.takeDamage(150); // Kill fighter2
        fighter4 = fighter5;      // Assign dead fighter to fighter4
        fighter4.attack("Battle Droids");

        std::cout << "\n=== TEST 4: Dynamic Allocation (new/delete) ===" << std::endl;
        FragTrap *dynamicFighter = new FragTrap("Yoda");
        dynamicFighter->highFivesGuys();
        delete dynamicFighter;

        std::cout << "\n=== BATTLE START ===" << std::endl;

        std::cout << "\n--- ROUND 1 ---" << std::endl;
        fighter1.attack("Obi-Wan");
        fighter2.takeDamage(7);

        std::cout << "\n--- ROUND 2 ---" << std::endl;
        fighter2.attack("Anakin");
        fighter1.takeDamage(5);

        std::cout << "\n--- SELF REPAIR ---" << std::endl;
        fighter1.beRepaired(5);
        fighter2.beRepaired(3);

        std::cout << "\n--- ENERGY DRAIN TEST ---" << std::endl;
        for (int i = 0; i < 12; ++i)
        {
            fighter1.attack("Training Dummy");
        }

        std::cout << "\n--- HIGH FIVE MODE ---" << std::endl;
        fighter2.highFivesGuys();

        std::cout << "\n--- CRITICAL DAMAGE TEST ---" << std::endl;
        fighter2.takeDamage(50);
        fighter2.takeDamage(60);   // Overkill testing
        fighter2.attack("Anakin"); // Dead man cannot attack

        std::cout << "\n--- ZOMBIE REPAIR TEST ---" << std::endl;
        fighter2.beRepaired(20); // Dead man cannot heal

        std::cout << "\n=== BATTLE END ===" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught during battle: " << e.what() << std::endl;
        return (1);
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during battle!" << std::endl;
        return (1);
    }

    return (0);
}
