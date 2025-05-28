#include "PhoneBook.hpp"

// Default constructor
PhoneBook::PhoneBook()
{
    index_ = 0;
}

// Getter for index_
int PhoneBook::getIndex() const
{
	return (index_);
}

// private method to get the proper index for the contacts array
int PhoneBook::getProperIndex()
{
    return (index_ % CONTACT_NUMBER);
}

// Get a contact from the contacts array
Contact PhoneBook::getContact(int index)
{
    if (index < FIRST_INDEX || index >= CONTACT_NUMBER)
        return (Contact());
    return (contacts_[index]);
}

// Add a contact to the contacts array
void PhoneBook::Add(const std::string fields[5]) {
    int i = getProperIndex();
    contacts_[i] = Contact(fields);
    (index_)++;
}
