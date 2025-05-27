#include "PhoneBook.hpp"
#include "iomanip"
#include "utils.hpp"

static void	displayAll(PhoneBook &phoneBook);
static bool	isIndexValid(std::string prompt);
static int	ft_atoi(const std::string &str);
static std::string truncateField(std::string field);
static int	searchLoop(PhoneBook *phoneBook, std::string &prompt);

Status	searchProcess(PhoneBook *phoneBook)
{
	int	index;

	std::string prompt;
	if (phoneBook->getIndex() <= 0)
	{
		std::cout << "The phonebook is empty. No contacts have been added yet.\n";
		return (SUCCESS);
	}
	displayAll(*phoneBook);
	std::cout << "\n";
	index = searchLoop(phoneBook, prompt);
	if (index == -1)
	{
		return (FAILURE);
	}
	phoneBook->getContact(index).printContacts();
	return (SUCCESS);
}

static int	searchLoop(PhoneBook *phoneBook, std::string &prompt)
{
	int index;

	while (true)
	{
		std::cout << "Enter the index of the contact you want to search for: ";
		if (!getInput(&prompt))
		{
			return (-1);
		}
		if (prompt.empty())
		{
			std::cout << "Empty input. Please enter an index.\n";
			continue ;
		}
		if (isIndexValid(prompt))
		{
			index = ft_atoi(prompt);
			if (index >= phoneBook->getIndex())
			{
				std::cout << "Invalid index. Please enter a number less than " << phoneBook->getIndex() << "\n";
				continue ;
			}
			break ;
		}
		else
		{
			continue ;
		}
	}
	return (index);
}

static void	displayAll(PhoneBook &phoneBook)
{
	std::cout << std::right;
	std::cout << "\n|";
	std::cout << std::setw(10) << "Index"
				<< "|"
				<< std::setw(10) << "Name"
				<< "|"
				<< std::setw(10) << "Surname"
				<< "|"
				<< std::setw(10) << "Nickname"
				<< "|";
	std::cout << "\n";
	std::cout << "---------------------------------------------\n";
	for (int i = 0; i < phoneBook.getIndex() && i < CONTACT_NUMBER; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i
					<< "|"
					<< std::setw(10) << truncateField(phoneBook.getContact(i).getName())
					<< "|"
					<< std::setw(10) << truncateField(phoneBook.getContact(i).getSurname())
					<< "|"
					<< std::setw(10) << truncateField(phoneBook.getContact(i).getNickname())
					<< "|";
		std::cout << "\n";
	}
}

static bool	isIndexValid(std::string prompt)
{
	int	index;

	for (std::size_t i = 0; i < prompt.length(); ++i)
	{
		if (!std::isdigit(prompt[i]))
		{
			std::cout << "Invalid index. Please enter a valid number.\n";
			return (false);
		}
	}
	index = ft_atoi(prompt);
	if (index < 0 || index >= CONTACT_NUMBER)
	{
		std::cout << "Index out of range. Please enter a number between 0 and 7.\n";
		return (false);
	}
	return (true);
}

static int	ft_atoi(const std::string &str)
{
	int		result;
	char	c;

	result = 0;
	for (std::size_t i = 0; i < str.length(); ++i)
	{
		c = str[i];
		if (c < '0' || c > '9')
			return (-1);
		result = (result * 10) + (c - '0');
	}
	return (result);
}

static std::string truncateField(std::string field)
{
	if (field.length() > 10)
	{
		return (field.substr(0, 9) + ".");
	}
	return (field);
}
