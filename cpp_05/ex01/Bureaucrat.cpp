#include "Bureaucrat.hpp"
#include "Form.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name_("Default"), grade_(150)
{
    std::cout << "Default constructor called for Bureaucrat: " << name_ << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name_(name), grade_(grade)
{
    if (grade_ < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (grade_ > LOWEST_GRADE)
        throw GradeTooLowException();

    std::cout << "Parameterised constructor called for Bureaucrat: " << name_ << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_), grade_(other.grade_)
{
    std::cout << "Copy constructor called for Bureaucrat: " << name_ << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called for Bureaucrat: " << name_ << std::endl;
}

// Assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        std::cout << "Assignment operator called for Bureaucrat: " << name_ << std::endl;
        grade_ = other.grade_;
    }
    return (*this);
}

// ============== Getters and Setters ==============

const std::string &Bureaucrat::getName() const
{
    return (name_);
}

int Bureaucrat::getGrade() const
{
    return (grade_);
}

// ============== Member Functions ==============

void Bureaucrat::incrementGrade()
{
    if (grade_ <= HIGHEST_GRADE)
        throw GradeTooHighException();
    (grade_)--;
}

void Bureaucrat::decrementGrade()
{
    if (grade_ >= LOWEST_GRADE)
        throw GradeTooLowException();
    (grade_)++;
}

void Bureaucrat::signForm(Form &form)
{
    if (form.getIsSigned())
    {
        std::cout   << this->name_ << " could not sign " << form.getName()
                    << " because it has already signed." << std::endl;
        return ;
    }

    try
    {
        form.beSigned(*this);
        std::cout   << this->name_ << " signs " 
                    << form.getName() << "." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout   << this->name_ << " could not sign " << form.getName()
                    << " because " << e.what() << std::endl;
    }
}

// ===================== Exception Classes =====================

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too HIGH! Must be between 1 and 150.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too LOW! Must be between 1 and 150.");
}

// Output operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur)
{
	os << "Name: " << bur.getName() << "\n"
	   << "Grade: " << bur.getGrade() << std::endl;

	return (os);
}
