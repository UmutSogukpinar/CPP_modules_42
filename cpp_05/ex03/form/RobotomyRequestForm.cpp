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
			  << name_ << std::endl;
}

// Parameterized Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string name)
	: AForm(name, RR_SIGN_GRADE, RR_EXEC_GRADE)
{
	std::cout << "Parameterized constructor called for RobotomyRequestForm "
			  << name_ << std::endl;
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: AForm(other.name_, other.signGrade_, other.executeGrade_)
{
	std::cout << "Copy constructor called for RobotomyRequestForm: "
			  << name_ << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called for RobotomyRequestForm: "
			  << name_ << std::endl;
}

// Operator Assignment
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		std::cout << "Assignment operator called for RobotomyRequestForm: "
				  << name_ << std::endl;
		isSigned_ = other.isSigned_;
	}
	return (*this);
}

// ========================== Member Functions ==========================

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSigned())
		throw UnsignedExecutionException();

	if (bureaucrat.getGrade() > this->getExecuteGrade())
		throw ExecGradeException();

	std::cout << "* Drilling noises * brrrrrrrrrrr..." << std::endl;

	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << name_ << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << name_ << std::endl;
}
