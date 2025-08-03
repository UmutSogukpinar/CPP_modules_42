#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm(RR_NAME, RR_SIGN_GRADE, RR_EXEC_GRADE)
{
	std::cout << "Default constructor called for RobotomyRequestForm "
			  << name_ << "\n";
}

// Parameterized Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string name)
	: AForm(name, RR_SIGN_GRADE, RR_EXEC_GRADE)
{
	std::cout << "Parameterized constructor called for RobotomyRequestForm "
			  << name_ << "\n";
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: AForm(other.name_, other.signGrade_, other.executeGrade_)
{
	std::cout << "Copy constructor called for RobotomyRequestForm: "
			  << name_ << "\n";
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called for RobotomyRequestForm: "
			  << name_ << "\n";
}

// Operator Assignment
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		std::cout << "Assignment operator called for RobotomyRequestForm: "
				  << name_ << "\n";
		isSigned_ = other.isSigned_;
	}
	return (*this);
}

// ========================== Member Functions ==========================

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat)
{
	if (!this->getIsSigned())
		throw std::runtime_error("Form must be signed before execution.");
	if (bureaucrat.getGrade() > this->getExecuteGrade())
		throw std::runtime_error("Bureaucrat grade too low to execute this form.");

	std::cout << "* Drilling noises * brrrrrrrrrrr... 🛠️🤖\n";

	std::srand(std::time(0)); // TODO: Implement proper place?
	if (std::rand() % 2)
		std::cout << name_ << " has been robotomized successfully.\n";
	else
		std::cout << "Robotomy failed on " << name_ << ".\n";
}
