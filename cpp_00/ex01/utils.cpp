#include "iostream"
#include "PhoneBook.hpp"
#include "utils.hpp"

bool getInput(std::string* prompt)
{
    std::getline(std::cin, *prompt);

    if (std::cin.eof())
    {
        return (false);
    }
    if (std::cin.fail())
    {
        std::cerr << "Reading input failed!\n";
        std::cin.clear();               // ? is this necessary?
        std::cin.ignore(10000, '\n');   // ? is this necessary?
        return (false);
    }
    return (true);
}

Status addProcess(PhoneBook* phoneBook)
{
    std::string prompt;
    std::string fields[5];
    std::string fieldNames[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};

    for (int i = 0; i < 5; ++i)
    {
        std::cout << fieldNames[i] << ": ";
        
        if (!getInput(&prompt))
        {
            return (Status::FAILURE);
        }

        if (prompt.empty())
        {
            --i;
            std::cout << "Empty input. Please enter a value for " << fieldNames[i] << ".\n";
            continue;
        }

        // * Implement validation for each field here if needed

    }
    phoneBook->Add(fields);
    return (Status::SUCCESS);
}

Status searchProcess(PhoneBook* phoneBook)
{
    std::string prompt;
    int index;

    while (true)
    {
        std::cout << "Enter the index of the contact you want to search for: ";
    
        if (!getInput(&prompt))
        {
            return (Status::FAILURE);
        }
        if (prompt.empty())
        {
            std::cout << "Empty input. Please enter an index.\n";
            continue;
        }

        if (isIndexValid(prompt))
        {
            index = std::stoi(prompt);
            break;
        }
        else
        {
            continue;
        }

    }
    phoneBook->getContact(index).printContacts();
    return (Status::SUCCESS);
}

static void printContact(Contact contact)
{
    std::cout << "First Name: " << contact.getName() << "\n";
    std::cout << "Last Name: " << contact.getSurname() << "\n";
    std::cout << "Nickname: " << contact.getNickname() << "\n";
    std::cout << "Phone Number: " << contact.getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << "\n";
}

static bool isIndexValid(std::string prompt)
{
    for (char c : prompt)
    {
        if (!std::isdigit(c))
        {
            std::cout << "Invalid index. Please enter a valid number.\n";
            return (false);
        }
    }
    int index = std::stoi(prompt);
    if (index < 0 || index >= 8)
    {
        std::cout << "Index out of range. Please enter a number between 0 and 7.\n";
        return (false);
    }
    return (true);
}
