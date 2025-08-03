#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(SC_NAME, SC_SIGN_GRADE, SC_EXEC_GRADE)
{
    std::cout << "Default constructor called for ShrubberyCreationForm "
			  << name_ << "\n";
}

// Parameterized Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: AForm(name, SC_SIGN_GRADE, SC_EXEC_GRADE)
{
	std::cout << "Parameterized constructor called for ShrubberyCreationForm "
			  << name_ << "\n";
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other.name_, other.signGrade_, other.executeGrade_)
{
	std::cout   << "Copy constructor called for ShrubberyCreationForm: "
                << name_ << "\n";
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout   << "Destructor called for ShrubberyCreationForm: "
                << name_ << "\n";
}

// Operator assignment
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		std::cout << "Assignment operator called for AForm: " << name_ << "\n";
		isSigned_ = other.isSigned_;
	}
	return (*this);
}

// ========================== Member Functions ==========================

static const char *tree_ascii =
"       /\\\n"
"      /  \\\n"
"     /++++\\\n"
"    /  ++  \\\n"
"   /++++++\\\n"
"      ||\n";

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSigned())
		throw std::runtime_error("Form must be signed before execution.");
	if (bureaucrat.getGrade() > this->getExecuteGrade())
		throw std::runtime_error("Bureaucrat grade too low to execute this form.");

	std::ofstream outFile((this->name_ + "_shrubbery").c_str());
	if (!outFile)
		throw std::runtime_error("Failed to open file for writing.");
 
	outFile << tree_ascii;
	outFile.close();
}