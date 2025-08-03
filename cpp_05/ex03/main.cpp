#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 50);
		Bureaucrat tom("Tom", 140);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("marvin");
		PresidentialPardonForm pardon("arthur");

		std::cout << "\n--- Signing Forms ---\n";
		tom.signForm(shrub);
		bob.signForm(robo);
		alice.signForm(pardon);

		std::cout << "\n--- Executing Forms ---\n";
		tom.executeForm(shrub);
		bob.executeForm(robo);
		alice.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}

	return (0);
}
