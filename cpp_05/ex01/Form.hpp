#ifndef FORM_HPP
# define FORM_HPP

# include "iostream"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

class Form
{
private:
	std::string const	name_;
	bool				isSigned_;
	int const			signGrade_;
	int const			executeGrade_;

public:
	// Constructors
	Form();
	Form(const std::string &name, int signGrade, int executeGrade);

	// Copy Constructor
	Form(const Form &other);

	// Destructor
	~Form();

	// Assignment Operator
	Form &operator=(const Form &other);

	// Exception classes
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	// Getters
	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	// Member Functions

	void beSigned(Bureaucrat const &bureaucrat);
};

// Output Operator
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif