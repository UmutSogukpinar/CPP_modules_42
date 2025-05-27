#include "iostream"
#include "iomanip"
#include "Contact.hpp"

// ====================  Constructors ====================

// Default constructor
Contact::Contact()
{
    name_ = "";
    surname_ = "";
    nickname_ = "";
    phoneNumber_ = "";
    darkestSecret_ = "";
}

// Constructor with parameters
Contact::Contact(const std::string fields[5]) 
{
    name_ = fields[0];
    surname_ = fields[1];
    nickname_ = fields[2];
    phoneNumber_ = fields[3];
    darkestSecret_ = fields[4];
}


// ====================  Getters ====================

std::string Contact::getName() const
{
    return (name_);
}

std::string Contact::getSurname() const
{
    return (surname_);
}

std::string Contact::getNickname() const
{
    return (nickname_);
}

std::string Contact::getPhoneNumber() const
{
    return (phoneNumber_);
}

std::string Contact::getDarkestSecret() const
{
    return (darkestSecret_);
}

// ====================  Methods ====================

static std::string truncateField(std::string field);

void Contact::printContacts() const
{
    std::cout << std::right;

    std::cout << "First Name:" << std::setw(10) << truncateField(name_) << "|";
    std::cout << "Last Name:" << std::setw(10) << truncateField(surname_) << "|";
    std::cout << "Nickname:" << std::setw(10) << truncateField(nickname_) << "|";
    std::cout << "Phone Number:" << std::setw(10) << truncateField(phoneNumber_) << "|";
    std::cout << "Darkest Secret:" << std::setw(10) << truncateField(darkestSecret_) << "\n";
}

static std::string truncateField(std::string field)
{
    if (field.length() > 10)
    {
        return (field.substr(0, 9) + ".");
    }
    return (field);
}
