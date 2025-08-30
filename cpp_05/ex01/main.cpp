#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "<-- Constructors -->" << std::endl;
    Bureaucrat b1("John", 1);
    Bureaucrat b2("Jane", 150);
    Bureaucrat b3("Jack", 1);
    Bureaucrat b4("Bureaucrat1", 50);

    Form f1("Form1", 50, 50);
    Form f2("Form2", 50, 50);

	// Invalid ctor
    // Rule expected by subject: 1 <= grade <= 150
    std::cout << "<-- Invalid Ctor: Form -->"<< std::endl;
    try {
        Form badForm("BadForm", 0, 50);  // invalid: sign grade 0 (too high)
        std::cout << "This is not supposed to print: " << badForm.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Form ctor failed as expected: " << e.what() << "\n" << std::endl;
    }

    std::cout << "<-- No Exception -->" << std::endl;
    try {
        b1.decrementGrade(); // valid: 1 -> 2
        std::cout << "Successfully changed grade of " << b1.getName() << "\n" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n" << std::endl;
    }

    std::cout << "<-- GradeTooLowException -->" << std::endl;
    try {
        b2.decrementGrade(); // invalid: 150 -> 151
        std::cout << "Successfully changed grade of " << b2.getName() << "\n" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n" << std::endl;
    }

    std::cout << "<-- GradeTooHighException -->" << std::endl;
    try {
        b3.incrementGrade(); // invalid: 1 -> 0
        std::cout << "Successfully changed grade of " << b3.getName() << "\n" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n" << std::endl;
    }

    std::cout << "<-- Tests With Form -->" << std::endl;
    std::cout << f1 << std::endl;

    std::cout << "<-- Form No Exception -->" << std::endl;
    b4.signForm(f1);
    std::cout << f1 << std::endl;

    std::cout << "<-- Signing Form Again -->" << std::endl;
    b4.signForm(f1);          // signing again (is not supposed to do)
    std::cout << std::endl;

    std::cout << "<-- Form GradeTooLowException -->" << std::endl;
    b4.decrementGrade();
    b4.signForm(f2);
    std::cout << std::endl;

    std::cout << "<-- Invalid Ctors -->" << std::endl;
    // Constructor validation is expected to enforce: 1 <= grade <= 150

    try {
        // Invalid: sign-grade too high (0)
        Form badFormHigh("BadFormHigh", 0, 50);
        std::cout << badFormHigh << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception from Form ctor (too high): " << e.what() << std::endl;
    }

    try {
        // Invalid: bureaucrat grade too low (151)
        Bureaucrat badBuro("BadBureaucrat", 151);
        std::cout << badBuro << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception from Bureaucrat ctor (too low): " << e.what() << std::endl;
    }

    try {
        // Invalid: exec-grade too low (151)
        Form badFormLow("BadFormLow", 50, 151);
        std::cout << badFormLow << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception from Form ctor (too low): " << e.what() << std::endl;
    }

    std::cout << "<-- Destructors -->" << std::endl;

    return (EXIT_SUCCESS);
}
