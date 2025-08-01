#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"
#include "stdexcept"

class Bureaucrat
{
private:
    std::string const   name_;
    int                 grade_;

public:
	// Constructors and Destructor
	Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();

	// Copy constructor and assignment operator
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	// Getters
    const std::string& getName() const;
    int getGrade() const;

	// Member Functions
    void incrementGrade();
    void decrementGrade();

	// ==================== Exception classes ====================

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif
