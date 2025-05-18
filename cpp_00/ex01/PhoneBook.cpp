#include "PhoneBook.hpp"

// Default constructor
PhoneBook::PhoneBook()
{
    index_ = 0;
}

// private method to get the proper index for the contacts array
int PhoneBook::getProperIndex()
{
    return (index_ % 8);
}

// Get a contact from the contacts array
Contact PhoneBook::getContact(int index)
{
    if (index < 0 || index >= 8)
        return (Contact());
    return (contacts_[index]);
}

// Add a contact to the contacts array
void PhoneBook::Add(const std::string fields[5]) {
    int i = getProperIndex();
    contacts_[i] = Contact(fields);
    index_++;
}
