#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Default constructor called for Bureaucrat: " << name << "\n";
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade) 
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Copy constructor called for Bureaucrat: " << name << "\n";
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called for Bureaucrat: " << name << "\n";
}

// Assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		std::cout << "Assignment operator called for Bureaucrat: " << name << "\n";
		grade = other.grade;
	}
	return (*this);
}

// ============== Getters and Setters ==============

const std::string& Bureaucrat::getName() const 
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

// ============== Member Functions ==============

void Bureaucrat::incrementGrade() 
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() 
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

// ===================== Exception Classes =====================

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return ("Grade too HIGH! Must be between 1 and 150.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return ("Grade too LOW! Must be between 1 and 150.");
}