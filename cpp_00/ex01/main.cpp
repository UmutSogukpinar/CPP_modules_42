#include "cstdlib"
#include "PhoneBook.hpp"
#include "utils.hpp"

static Status generealProcess(PhoneBook* phoneBook, std::string prompt);

int main()
{
	PhoneBook	phoneBook;
	std::string	prompt;
	Status		exitStatus = SUCCESS;

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

        if (exitStatus == EXIT)
        {
            std::cout << "Exiting the program.\n";
            break;
        }
        else if (exitStatus == FAILURE)
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
        return (searchProcess(phoneBook));
    }
    else if (prompt == "EXIT")
    {
        return (EXIT);
    }
    else
    {
        std::cout << "Invalid command. Please try again.\n";
        return (SUCCESS);
    }
}
