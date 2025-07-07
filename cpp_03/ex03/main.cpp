#include <stdexcept>
#include "DiamondTrap.hpp"

int main()
{
    try
    {
        std::cout << "\n=== TEST 0: Default Constructor Test ===" << std::endl;
        DiamondTrap defaultTrap;
        defaultTrap.guardGate();
        defaultTrap.highFivesGuys();

        std::cout << "\n=== TEST 1: Parameterized Constructor Test ===" << std::endl;
        DiamondTrap trap1("Anakin");
        DiamondTrap trap2("Obi-Wan");

        trap1.guardGate();
        trap1.highFivesGuys();

        std::cout << "\n=== TEST 2: Copy Constructor Test ===" << std::endl;
        DiamondTrap trap3(trap1);
        trap3.whoAmI();
        trap3.guardGate();
        trap3.highFivesGuys();

        std::cout << "\n=== TEST 3: Assignment Operator Test ===" << std::endl;
        DiamondTrap trap4;
        trap4 = trap2;
        trap4.attack("General Grievous");
        trap4.guardGate();
        trap4.highFivesGuys();

        std::cout << "\n--- Chain Assignment Test ---" << std::endl;
        DiamondTrap trap5("R2-D2");
        DiamondTrap trap6("Padme");
        trap5 = trap6 = trap2;
        trap5.attack("Battle Droids");
        trap6.attack("Battle Droids");

        std::cout << "\n--- Assignment After Destroyed State ---" << std::endl;
        trap5.takeDamage(200);
        trap4 = trap5;
        trap4.attack("Clone Troopers");

        std::cout << "\n=== TEST 4: Dynamic Allocation (new/delete) ===" << std::endl;
        DiamondTrap *dynamicTrap = new DiamondTrap("Yoda");
        dynamicTrap->whoAmI();
        dynamicTrap->attack("Palpatine");
        dynamicTrap->guardGate();
        dynamicTrap->highFivesGuys();
        delete dynamicTrap;

        std::cout << "\n=== BATTLE START ===" << std::endl;

        std::cout << "\n--- ROUND 1 ---" << std::endl;
        trap1.attack("Obi-Wan");
        trap2.takeDamage(10);

        std::cout << "\n--- ROUND 2 ---" << std::endl;
        trap2.attack("Anakin");
        trap1.takeDamage(15);

        std::cout << "\n--- SELF REPAIR ---" << std::endl;
        trap1.beRepaired(10);
        trap2.beRepaired(5);

        std::cout << "\n--- ENERGY DRAIN TEST ---" << std::endl;
        for (int i = 0; i < 12; ++i)
        {
            trap1.attack("Training Dummy");
        }

        std::cout << "\n--- WHOAMI TEST ---\n";
        trap2.whoAmI();

        std::cout << "\n--- SPECIAL SKILLS TEST ---" << std::endl;
        trap2.guardGate();
        trap2.highFivesGuys();

        std::cout << "\n--- CRITICAL DAMAGE TEST ---" << std::endl;
        trap2.takeDamage(80);
        trap2.takeDamage(100);
        trap2.attack("Anakin");

        std::cout << "\n--- ZOMBIE REPAIR TEST ---" << std::endl;
        trap2.beRepaired(20);

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
