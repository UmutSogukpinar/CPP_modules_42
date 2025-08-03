#ifndef INTERN_HPP
# define INTERN_HPP

# include "iostream"
# include "AForm.hpp"

class Intern
{
	public:
		AForm *makeForm(std::string name, std::string target);
};

#endif