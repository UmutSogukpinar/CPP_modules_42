#include "PhoneBook.hpp"
#include "utils.hpp"

static bool	isInvalidPrompt(std::string prompt, int fieldIndex);

// * Read input from standard input into the given string
bool	getInput(std::string *prompt)
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
// * Add a new contact to the contacts array
Status	addProcess(PhoneBook *phoneBook)
{
	std::string prompt;
	std::string fields[5];
	std::string fieldNames[5] = {"First Name", "Last Name", "Nickname",
		"Phone Number", "Darkest Secret"};
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
			continue ;
		}
		// * Implement validation for each field here if needed
		if (isInvalidPrompt(prompt, i))
		{
			std::cout << "Invalid input. Please enter a valid value for " << fieldNames[i] << ".\n";
			--i;
			continue ;
		}
		fields[i] = prompt;
	}
	phoneBook->Add(fields);
	std::cout << "Contact added successfully!\n";
	return (SUCCESS);
}

// * Check whether the promp valid or not
static bool	isInvalidPrompt(std::string prompt, int fieldIndex)
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
			if (!std::isalpha(prompt[i]) && prompt[i] == ' ')
			{
				return (true);
			}
		}
	}
	return (false);
}

