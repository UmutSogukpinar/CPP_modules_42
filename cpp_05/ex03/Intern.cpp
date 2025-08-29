#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

static std::string toStrLower(const std::string& str);

Intern::Intern()
{
    std::cout << "Intern created." << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destroyed." << std::endl;
}

Intern::Intern(Intern const & other)
{
	(void) other;
    std::cout << "Intern copied." << std::endl;
}

// Assignment Operator
Intern & Intern::operator=(const Intern& other)
{
    if (this != &other)
	{
        std::cout << "Intern assigned." << std::endl;
    }
    return (*this);
}

AForm* Intern::makeForm(std::string formType, std::string formTarget)
{
	if (formType.empty() || formTarget.empty())
		throw (FormNotExists());

	std::string lowerStr = toStrLower(formType);

	std::string formLst[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*ptrMember[3])(std::string&) =
	{
		&Intern::CreateShrubberyCreation,
		&Intern::CreateRobotomyRequest,
		&Intern::CreatePresidentialPardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (lowerStr == formLst[i])
		{
			AForm *form = (this->*ptrMember[i])(formTarget);
			std::cout << "Intern creates " << *form << std::endl;
			return (form);
		}
	}
	throw (FormNotExists());
}

// Example creator functions
AForm* Intern::CreateShrubberyCreation(std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::CreateRobotomyRequest(std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::CreatePresidentialPardon(std::string& target)
{
	return (new PresidentialPardonForm(target));
}

// Exception override
const char* Intern::FormNotExists::what() const throw()
{
	return ("Intern: Requested form type does not exist.");
}

// ============================= Util(s) =============================

static std::string toStrLower(const std::string& str)
{
	std::string result = str;
	for (std::size_t i = 0; i < result.length(); ++i)
		result[i] = std::tolower(static_cast<unsigned char>(result[i]));
	return (result);
}