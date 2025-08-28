#ifndef AFORM_HPP
# define AFORM_HPP

# include "iostream"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

class AForm
{
	protected:
		std::string const	name_;
		bool				isSigned_;
		int const			signGrade_;
		int const			executeGrade_;

	public:
		// Constructors
		AForm();
		AForm(const std::string &name, int signGrade, int executeGrade);

		// Copy Constructor
		AForm(const AForm &other);

		// Destructor
		virtual ~AForm();

		// Assignment Operator
		AForm &operator=(const AForm &other);

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
		virtual void execute(Bureaucrat const &bureaucrat) const = 0;
};

// Output Operator
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif