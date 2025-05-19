#include "iostream"
#include "PhoneBook.hpp"
#include "utils.hpp"

static Status generealProcess(PhoneBook* phoneBook, std::string prompt);

int main()
{
    PhoneBook   phoneBook;
    std::string prompt;
    Status      exitStatus;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";

        if (!getInput(&prompt))
        {
            std::cerr << "Error reading input. Exiting...\n";
            return (EXIT_FAILURE);
        }
        if (prompt.empty())
        {
            std::cout << "Empty input. Please enter a command.\n";
            continue;
        }

        exitStatus = generealProcess(&phoneBook, prompt);

        if (exitStatus == Status::EXIT)
        {
            std::cout << "Exiting the program.\n";
            break;
        }
        else if (exitStatus == Status::FAILURE)
        {
            std::cout << "An error occurred\n";
            return (EXIT_FAILURE);
        }
    }
    return (EXIT_SUCCESS);
}

static Status generealProcess(PhoneBook* phoneBook, std::string prompt)
{
    if (prompt == "ADD")
    {
        return (addProcess(phoneBook));
    }
    else if (prompt == "SEARCH")
    {
        // * Implement search functionality here
        return (Status::SUCCESS);
    }
    else if (prompt == "EXIT")
    {
        return (Status::SUCCESS);
    }
    else
    {
        std::cout << "Invalid command. Please try again.\n";
        return (Status::SUCCESS);
    }
}
