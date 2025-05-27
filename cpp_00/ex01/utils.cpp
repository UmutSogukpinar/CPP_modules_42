#include "iostream"
#include "PhoneBook.hpp"
#include "utils.hpp"

static bool isInvalidPrompt(std::string prompt, int fieldIndex);
static bool isIndexValid(std::string prompt);
static int  ft_atoi(const std::string& str);

bool        getInput(std::string* prompt)
{
    std::getline(std::cin, *prompt);

    if (std::cin.eof())
    {
        return (false);
    }
    if (std::cin.fail())
    {
        std::cerr << "Reading input failed!\n";
        return (false);
    }
    return (true);
}

Status      addProcess(PhoneBook* phoneBook)
{
    std::string prompt;
    std::string fields[5];
    std::string fieldNames[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};

    for (int i = 0; i < 5; ++i)
    {
        std::cout << fieldNames[i] << ": ";
        
        if (!getInput(&prompt))
        {
            return (FAILURE);
        }

        if (prompt.empty())
        {
            std::cout << "Empty input. Please enter a value for " << fieldNames[i] << ".\n";
            --i;
            continue;
        }

        // * Implement validation for each field here if needed
        if (isInvalidPrompt(prompt, i))
        {
            std::cout << "Invalid input. Please enter a valid value for " << fieldNames[i] << ".\n";
            --i;
            continue;
        }

        fields[i] = prompt;

    }
    phoneBook->Add(fields);
    std::cout << "Contact added successfully!\n";
    return (SUCCESS);
}

Status      searchProcess(PhoneBook* phoneBook)
{
    std::string prompt;
    int index;

    while (true)
    {
        std::cout << "Enter the index of the contact you want to search for: ";
    
        if (!getInput(&prompt))
        {
            return (FAILURE);
        }
        if (prompt.empty())
        {
            std::cout << "Empty input. Please enter an index.\n";
            continue;
        }

        if (isIndexValid(prompt))
        {
            index = ft_atoi(prompt);
            break;
        }
        else
        {
            continue;
        }

    }
    phoneBook->getContact(index).printContacts();
    return (SUCCESS);
}

static bool isIndexValid(std::string prompt)
{
    for (std::size_t i = 0; i < prompt.length(); ++i)
    {
        if (!std::isdigit(prompt[i]))
        {
            std::cout << "Invalid index. Please enter a valid number.\n";
            return (false);
        }
    }

    int index = ft_atoi(prompt);
    if (index < 0 || index >= CONTACT_NUMBER)
    {
        std::cout << "Index out of range. Please enter a number between 0 and 7.\n";
        return (false);
    }

    return (true);
}

static bool isInvalidPrompt(std::string prompt, int fieldIndex)
{
    if (fieldIndex == 3) // Phone Number
    {
        if (prompt.length() != 10)
        {
            return (true);
        }
        for (std::size_t i = 0; i < prompt.length(); ++i)
        {
            if (!std::isdigit(prompt[i]))
            {
                return (true);
            }
        }
    }

    if (fieldIndex < 2)
    {
        for (std::size_t i = 0; i < prompt.length(); ++i)
        {
            if (!std::isalpha(prompt[i]) && prompt[i] != ' ')
            {
                return (true);
            }
        }
    }

    return (false);
}

int ft_atoi(const std::string& str)
{
    int result = 0;
    for (std::size_t i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        if (c < '0' || c > '9')
            return (-1);
        result = (result * 10) + (c - '0');
    }
    return (result);
}
