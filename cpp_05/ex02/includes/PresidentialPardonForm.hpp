#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

# define PP_SIGN_GRADE  25
# define PP_EXEC_GRADE  5
# define PP_NAME        "PresidentialPardonForm"

class PresidentialPardonForm : public AForm
{
	public:
		// Default Constructor
		PresidentialPardonForm();

		// Parameterized Constructor
		PresidentialPardonForm(std::string name);

		// Copy Constructor
		PresidentialPardonForm(PresidentialPardonForm const &other);

		// Destructor
		~PresidentialPardonForm();

		// Assignment Operator
		PresidentialPardonForm & operator=(PresidentialPardonForm const &other);

		// Member Functions

		void execute(Bureaucrat const &bureaucrat) const;
};

# endif