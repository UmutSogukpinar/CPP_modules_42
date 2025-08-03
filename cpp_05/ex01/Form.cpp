#include "Form.hpp"
#include "Bureaucrat.hpp"

// ================ Constructors and Destructor ================

// Default Constructor
Form::Form()
	: name_("Default"), isSigned_(false),
	  signGrade_(LOWEST_GRADE), executeGrade_(LOWEST_GRADE)
{
	std::cout << "Default constructor called for Form "
			  << name_ << "\n";
}

// Parameterized Constructors
Form::Form(const std::string &name, int signGrade, int executeGrade)
	: name_(name), isSigned_(false),
	  signGrade_(signGrade), executeGrade_(executeGrade)
{
	if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	else if (signGrade < HIGHEST_GRADE || executeGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else
		std::cout << "Parameterized constructor called for Form: "
				  << name << "\n";
}

// Destructor
Form::~Form()
{
	std::cout << "Destructor called for Form: " << name_ << "\n";
}

// Copy Constructor
Form::Form(const Form &other)
	: name_(other.name_), isSigned_(other.isSigned_),
	  signGrade_(other.signGrade_), executeGrade_(other.executeGrade_)
{
	std::cout << "Copy constructor called for Form: " << name_ << "\n";
}

// Assignment Operator
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		std::cout << "Assignment operator called for Form: " << name_ << "\n";
		isSigned_ = other.isSigned_;
	}
	return (*this);
}

// ========================= Exception classes =========================

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too HIGH!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too LOW!");
}

// =============================================== Member Function(s) ===============================================

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signGrade_)
		this->isSigned_ = true;
	else
		throw GradeTooLowException();
}

// ============ Getters ============

std::string Form::getName() const
{
	return (name_);
}

bool Form::getIsSigned() const
{
	return (isSigned_);
}

int Form::getSignGrade() const
{
	return (signGrade_);
}

int Form::getExecuteGrade() const
{
	return (executeGrade_);
}

// Output operator
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Name: " << form.getName() << "\n"
	   << "Signed: " << (form.getIsSigned() ? "true" : "false") << "\n"
	   << "Sign Grade: " << form.getSignGrade() << "\n"
	   << "Execute Grade: " << form.getExecuteGrade() << "\n";

	return (os);
}
