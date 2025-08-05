#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern intern;

        std::cout << "\n--- Creating Forms ---\n";
        AForm *form1 = intern.makeForm("shrubbery creation", "home");
        AForm *form2 = intern.makeForm("robotomy request", "marvin");
        AForm *form3 = intern.makeForm("presidential pardon", "arthur");
        AForm *form4 = intern.makeForm("unknown form", "none");

        // Valid forms: form1, form2, form3
        if (form1)
            std::cout << "Created: " << form1->getName() << std::endl;
        if (form2)
            std::cout << "Created: " << form2->getName() << std::endl;
        if (form3)
            std::cout << "Created: " << form3->getName() << std::endl;

        // Invalid form type
        if (!form4)
            std::cout << "Form creation failed for 'unknown form'.\n";

        // Clean up dynamic memory
        delete (form1);
        delete (form2);
        delete (form3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return (0);
}
