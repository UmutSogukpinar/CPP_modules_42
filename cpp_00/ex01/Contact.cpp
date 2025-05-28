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


void Contact::printContacts() const
{
    std::cout << "First Name:" << (name_) << "\n";
    std::cout << "Last Name:" << (surname_) << "\n";
    std::cout << "Nickname:" << (nickname_) << "\n";
    std::cout << "Phone Number:" << (phoneNumber_) << "\n";
    std::cout << "Darkest Secret:" << (darkestSecret_) << "\n";
}
