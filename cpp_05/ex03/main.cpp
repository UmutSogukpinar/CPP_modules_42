#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Intern  intern;
    AForm  *form1 = NULL;
    AForm  *form2 = NULL;
    AForm  *form3 = NULL;
    AForm  *form4 = NULL;

    std::cout << "\n--- Creating Forms ---\n";

    // Shrubbery
    try {
        form1 = intern.makeForm("shrubbery creation", "home");
        std::cout << "Created: " << form1->getName() << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Form creation failed for 'shrubbery creation': " << e.what() << "\n";
    }

    // Robotomy
    try {
        form2 = intern.makeForm("robotomy request", "marvin");
        std::cout << "Created: " << form2->getName() << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Form creation failed for 'robotomy request': " << e.what() << "\n";
    }

    // Presidential Pardon
    try {
        form3 = intern.makeForm("presidential pardon", "arthur");
        std::cout << "Created: " << form3->getName() << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Form creation failed for 'presidential pardon': " << e.what() << "\n";
    }

    // Invalid
    try {
        form4 = intern.makeForm("unknown form", "none");
        std::cout << "Created: " << form4->getName() << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Form creation failed for 'unknown form': " << e.what() << "\n";
    }

    // Clean up
    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return (0);
}
