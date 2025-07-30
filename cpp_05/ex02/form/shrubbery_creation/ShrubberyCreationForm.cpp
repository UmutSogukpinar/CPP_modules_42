#include "ShrubberyCreationForm.hpp"

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(SC_NAME, SC_SIGN_GRADE, SC_EXEC_GRADE)
{
    std::cout << "Default constructor called for ShrubberyCreationForm "
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

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{

}
