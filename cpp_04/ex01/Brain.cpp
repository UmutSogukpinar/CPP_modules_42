#include "Brain.hpp"

// Default constructor
Brain::Brain()
{
	std::cout << "Brain default constructor called" << "\n";
}

// Copy constructor
Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << "\n";
	for (int i = 0; i < NUM_IDEAS; ++i)
	{
		ideas[i] = other.ideas[i];
	}
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain destructor called" << "\n";
}

// Overloaded '=' operator
Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignment operator called" << "\n";
	if (this != &other)
	{
		for (int i = 0; i < NUM_IDEAS; ++i)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

// Getters and Setters

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < NUM_IDEAS)
	{
		ideas[index] = idea;
	}
	else
	{
		throw std::out_of_range("Index out of bounds in Brain::setIdea");
	}
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < NUM_IDEAS)
	{
		return ideas[index];
	}
	else
	{
		throw std::out_of_range("Index out of bounds in Brain::getIdea");
	}
}

void Brain::displayIdeas() const
{
	for (int i = 0; i < NUM_IDEAS; ++i)
	{
		if (!ideas[i].empty())
			std::cout << "Idea [" << i << "]: " << ideas[i] << "\n";
	}
}

