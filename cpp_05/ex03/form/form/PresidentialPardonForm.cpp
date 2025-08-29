#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm()
    : AForm(PP_NAME, PP_SIGN_GRADE, PP_EXEC_GRADE)
{
    std::cout << "Default constructor called for PresidentialPardonForm "
              << name_ << std::endl;
}

// Parameterized Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string name)
    : AForm(name, PP_SIGN_GRADE, PP_EXEC_GRADE)
{
    std::cout << "Parameterized constructor called for PresidentialPardonForm "
              << name_ << std::endl;
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
    : AForm(other.name_, other.signGrade_, other.executeGrade_)
{
    std::cout << "Copy constructor called for PresidentialPardonForm: "
              << name_ << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor called for PresidentialPardonForm: "
              << name_ << std::endl;
}

// Operator assignment
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    if (this != &other)
    {
        std::cout << "Assignment operator called for PresidentialPardonForm: "
                  << name_ << std::endl;
        isSigned_ = other.isSigned_;
    }
    return (*this);
}

// ========================== Member Functions ==========================

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
    if (!this->getIsSigned())
        throw std::runtime_error("Form must be signed before execution.");
    if (bureaucrat.getGrade() > this->getExecuteGrade())
        throw ExecGradeException();

    std::cout << name_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
