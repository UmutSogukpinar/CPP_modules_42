#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define CONTACT_NUMBER 8
# define FIRST_INDEX 0

class PhoneBook
{
  private:
	// Fields
	Contact contacts_[CONTACT_NUMBER];
	int index_;

	// Methods
	int getProperIndex();

  public:
	// Constructor
	PhoneBook();

	// Methods
	Contact getContact(int index);
	void Add(const std::string fields[5]);
};

#endif
