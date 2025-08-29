#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    // Construct objects
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 50);
    Bureaucrat tom("Tom", 140);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm   robo("marvin");
    PresidentialPardonForm pardon("arthur");

    std::cout << "\n--- Signing Forms ---\n" << std::endl;

    try
    {
        tom.signForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cerr << "[tom.signForm(shrub)] " << e.what() << std::endl;
    }

    try
    {
        alice.signForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << "[alice.signForm(pardon)] " << e.what() << std::endl;
    }

    std::cout << "\n--- Executing Forms ---\n" << std::endl;

    try
    {
        tom.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cerr << "[tom.executeForm(shrub)] " << e.what() << std::endl;
    }

    try
    {
        bob.executeForm(robo);
    }
    catch (std::exception &e)
    {
        std::cerr << "[bob.executeForm(robo)] " << e.what() << std::endl;
    }

    try
    {
        alice.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << "[alice.executeForm(pardon)] " << e.what() << std::endl;
    }

    return (0);
}
