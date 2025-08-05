#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
	
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(std::string formType, std::string formTarget);

	private:
	
		AForm* CreateShrubberyCreation(std::string& target);
		AForm* CreateRobotomyRequest(std::string& target);
		AForm* CreatePresidentialPardon(std::string& target);

		class FormNotExists : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
};

#endif
