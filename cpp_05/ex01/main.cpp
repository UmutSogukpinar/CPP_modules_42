#include "Bureaucrat.hpp"
#include "cstdlib"

int main()
{
	std::cout << "<-- Constructors -->\n";
	Bureaucrat b1("John", 1);
	Bureaucrat b2("Jane", 150);
	Bureaucrat b3("Jack", 1);

	Form f1("Form1", 50, 50);
	Form f2("Form2", 50, 50);
	Bureaucrat b4("Bureaucrat1", 50);

	std::cout << "<-- No Exception -->\n";
	try {
		b1.decrementGrade();
		std::cout << "Successfully changed grade of " << b1.getName() << '\n';
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	std::cout << "<-- GradeTooLowException -->\n";
	try {
		b2.decrementGrade();
		std::cout << "Successfully changed grade of " << b2.getName() << '\n';
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "<-- GradeTooHighException -->\n";
	try {
		b3.incrementGrade();
		std::cout << "Successfully changed grade of " << b3.getName() << '\n';
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "<-- Tests With Form -->\n";
	std::cout << f1;

	std::cout << "<-- Form No Exception -->\n";
	b4.signForm(f1);
	std::cout << f1;

	std::cout << "<-- Signing Form Again -->\n";
	b4.signForm(f1);

	std::cout << "<-- Form GradeTooLowException -->\n";
	b4.decrementGrade();
	b4.signForm(f2);

	std::cout << "<-- Destructors -->\n";

	return (EXIT_SUCCESS);
}
