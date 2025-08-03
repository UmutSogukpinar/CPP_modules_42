#include "AForm.hpp"
# include "Bureaucrat.hpp"

// Constructors and Destructor

AForm::AForm()
	: name_("Default"), isSigned_(false),
	  signGrade_(LOWEST_GRADE), executeGrade_(LOWEST_GRADE)
{
	std::cout << "Default constructor called for AForm "
			  << name_ << "\n";
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: name_(name), isSigned_(false),
	  signGrade_(signGrade), executeGrade_(executeGrade)
{
	if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	else if (signGrade < HIGHEST_GRADE || executeGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else
		std::cout << "Parameterized constructor called for AForm: "
				  << name << "\n";
}

AForm::~AForm()
{
	std::cout << "Destructor called for AForm: " << name_ << "\n";
}

// Copy Constructor
AForm::AForm(const AForm &other)
	: name_(other.name_), isSigned_(other.isSigned_),
	  signGrade_(other.signGrade_), executeGrade_(other.executeGrade_)
{
	std::cout << "Copy constructor called for AForm: " << name_ << "\n";
}

// Assignment Operator
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		std::cout << "Assignment operator called for AForm: " << name_ << "\n";
		isSigned_ = other.isSigned_;
	}
	return (*this);
}

// Exception classes

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too HIGH!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too LOW!");
}

// Member Function(s)

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signGrade_)
		this->isSigned_ = true;
	else
		throw GradeTooLowException();
}

// ============ Getters ============

std::string AForm::getName() const
{
	return (name_);
}

bool AForm::getIsSigned() const
{
	return (isSigned_);
}

int AForm::getSignGrade() const
{
	return (signGrade_);
}

int AForm::getExecuteGrade() const
{
	return (executeGrade_);
}

// Output operator
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Name: " << form.getName() << "\n"
	   << "Signed: " << (form.getIsSigned() ? "true" : "false") << "\n"
	   << "Sign Grade: " << form.getSignGrade() << "\n"
	   << "Execute Grade: " << form.getExecuteGrade() << "\n";

	return (os);
}
