#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "<-- Constructors -->\n";
    Bureaucrat b1("John", 1);
    Bureaucrat b2("Jane", 150);
    Bureaucrat b3("Jack", 1);
    Bureaucrat b4("Bureaucrat1", 50);

    Form f1("Form1", 50, 50);
    Form f2("Form2", 50, 50);

	// Invalid ctor
    // Rule expected by subject: 1 <= grade <= 150
    std::cout << "<-- Invalid Ctor: Form -->\n";
    try {
        Form badForm("BadForm", 0, 50);  // invalid: sign grade 0 (too high)
        std::cout << "This should NOT print: " << badForm.getName() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Form ctor failed as expected: " << e.what() << "\n" << std::endl;
    }

    std::cout << "<-- No Exception -->\n";
    try {
        b1.decrementGrade(); // valid: 1 -> 2
        std::cout << "Successfully changed grade of " << b1.getName() << "\n\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n\n";
    }

    std::cout << "<-- GradeTooLowException -->\n";
    try {
        b2.decrementGrade(); // invalid: 150 -> 151
        std::cout << "Successfully changed grade of " << b2.getName() << "\n\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n\n";
    }

    std::cout << "<-- GradeTooHighException -->\n";
    try {
        b3.incrementGrade(); // invalid: 1 -> 0
        std::cout << "Successfully changed grade of " << b3.getName() << "\n\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n\n";
    }

    std::cout << "<-- Tests With Form -->\n";
    std::cout << f1 << "\n";

    std::cout << "<-- Form No Exception -->\n";
    b4.signForm(f1);
    std::cout << f1 << "\n";

    std::cout << "<-- Signing Form Again -->\n";
    b4.signForm(f1);          // signing again (should print already-signed info)
    std::cout << "\n";

    std::cout << "<-- Form GradeTooLowException -->\n";
    b4.decrementGrade();      // 50 -> 51
    b4.signForm(f2);
    std::cout << "\n";

    std::cout << "<-- Invalid Ctors (should throw) -->\n";
    // Constructor validation is expected to enforce: 1 <= grade <= 150

    try {
        // Invalid: sign-grade too high (0)
        Form badFormHigh("BadFormHigh", 0, 50);
        std::cout << badFormHigh << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Caught exception from Form ctor (too high): " << e.what() << "\n";
    }

    try {
        // Invalid: bureaucrat grade too low (151)
        Bureaucrat badBuro("BadBureaucrat", 151);
        std::cout << badBuro << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Caught exception from Bureaucrat ctor (too low): " << e.what() << "\n";
    }

    try {
        // Invalid: exec-grade too low (151)
        Form badFormLow("BadFormLow", 50, 151);
        std::cout << badFormLow << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Caught exception from Form ctor (too low): " << e.what() << "\n";
    }

    std::cout << "<-- Destructors -->\n";

    return (EXIT_SUCCESS);
}
