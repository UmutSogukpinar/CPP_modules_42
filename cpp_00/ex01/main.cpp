#include "PhoneBook.hpp"
#include <cstdlib>

static bool getInput(std::string* prompt);

int main()
{
    PhoneBook phoneBook;
    std::string prompt;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";

        if (!getInput(&prompt))
        {
            return (EXIT_FAILURE);
        }
        if (prompt == "EXIT")
        {
            break;
        }
        else if (prompt == "ADD")
        {
            if (addProcess(&phoneBook) == EXIT_FAILURE)
            {
                std::cerr << "Failed to add contact.\n";
                return (EXIT_FAILURE);
            }
        }
    }
    return (0);
}

static int addProcess(PhoneBook* phoneBook)
{
    std::string prompt;
    std::string fields[5];
    std::string fieldNames[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};

    for (int i = 0; i < 5; ++i)
    {
        std::cout << fieldNames[i] << ": ";
        
        if (!getInput(&prompt))
        {
            return (EXIT_FAILURE);
        }

        if (prompt.empty())
        {
            std::cout << fieldNames[i] << " cannot be empty. Please try again.\n";
            --i;
            continue;
        }

    }
    phoneBook->Add(fields);
    return (EXIT_SUCCESS);
}

static bool getInput(std::string* prompt)
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

    if (prompt->empty())
    {
        std::cout << "Empty input. Please enter a command.\n";
        return (true);
    }

    if (*prompt == "ADD" || *prompt == "SEARCH" || *prompt == "EXIT")
    {
        return (true);
    }

    std::cout << "Invalid command. Please try again.\n";
    return (true);
}

