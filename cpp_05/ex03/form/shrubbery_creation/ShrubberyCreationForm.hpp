#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

# define SC_SIGN_GRADE  145
# define SC_EXEC_GRADE  137
# define SC_NAME        "ShrubberyCreationForm"

class ShrubberyCreationForm : public AForm
{
	public:
		// Default Constructor
		ShrubberyCreationForm();

		// Parameterized Constructor
		ShrubberyCreationForm(std::string name);

		// Copy Constructor
		ShrubberyCreationForm(ShrubberyCreationForm const &other);

		// Destructor
		~ShrubberyCreationForm();

		// Assignment Operator
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &other);

		// Member Functions

		void execute(Bureaucrat const &bureaucrat) const;
};

#endif
