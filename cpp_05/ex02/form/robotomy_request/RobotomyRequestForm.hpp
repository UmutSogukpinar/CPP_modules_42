#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

# define RR_SIGN_GRADE  72
# define RR_EXEC_GRADE  45
# define RR_NAME        "RobotomyRequestForm"


class RobotomyRequestForm : public AForm
{
	public:
		// Default Constructor
		RobotomyRequestForm();

		// Parameterized Constructor
		RobotomyRequestForm(std::string name);

		// Copy Constructor
		RobotomyRequestForm(RobotomyRequestForm const &other);

		// Destructor
		~RobotomyRequestForm();

		// Assignment Operator
		RobotomyRequestForm & operator=(RobotomyRequestForm const &other);

		// Member Functions

		void execute(Bureaucrat const &bureaucrat) const;
};

# endif