#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "iostream"

class	Contact
{
	private:

		// Fields
		std::string	name_;
		std::string	surname_;
		std::string	nickname_;
		std::string	phoneNumber_;
		std::string	darkestSecret_;

	public:
	
		// Constructor
        Contact();
		Contact(const std::string fields[5]);

		// Getters
		std::string getName() const;
		std::string getSurname() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		// Methods
		void printContacts() const;


};

#endif
